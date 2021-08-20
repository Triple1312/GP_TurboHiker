
#include "Player.h"

#include <Utils/Random.hpp>

void logic::User::EmpCharge(
  const std::deque<std::shared_ptr<Player>>& players) {
  this->velocity_ = {0, 0, 0};
  auto temp = this->GetPosition();
  for (const std::shared_ptr<Player>& i : players) {
    if (i.get() != (Player*)this) {
      float distance = glm::length(i->GetPosition() - temp);
      i->speed_ = i->speed_ -  i->speed_ / distance;
    }
  }
  this->emp_charge_ = 0;
  this->empd_ += 1;
}

void logic::Player::Update() {
  this->score_ += Clock::Get()->GetTimeSinceLastInMilliSeconds();
  velocity_.y = velocity_.y + Clock::Get()->GetTimeSinceLastInSeconds() * -2.0;

  // calculates the next position
  this->MoveRight(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.x);
  this->MoveUp(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.y);
  this->MoveForward(Clock::Get()->GetTimeSinceLastInSeconds() *
                    this->velocity_.z);

  this->CalcVel();
  this->score_ += Clock::Get()->GetTimeSinceLastInSeconds() * 100;

  if (this->GetCenter().y < -2) {
    score_ = score_ /2;
      this->Respawn();
  }
}
void logic::Player::Jump() {
  if (airborne_) {
    return;
  }
  airborne_ = true;
  this->velocity_.y = GameSettings::JumpHeight();
}
void logic::Player::Bump(float stamina, glm::vec3 dir) {

}

void logic::Player::CalcVel() {
  if (velocity_.z > 2) {
    velocity_.z -= Clock::Get()->GetTimeSinceLastInSeconds() * 0.2;
    stamina_ += Clock::Get()->GetTimeSinceLastInSeconds() * 0.2;
    if (velocity_.z < this->MaxSpeed()) {
      velocity_.z = this->MaxSpeed();
    }

  } else if (velocity_.z < this->MaxSpeed() && stamina_ != 0) {
    velocity_.z += Clock::Get()->GetTimeSinceLastInSeconds() * 0.5;
    stamina_ -= Clock::Get()->GetTimeSinceLastInSeconds() * 0.1;
    if (velocity_.z > this->MaxSpeed()) {
      velocity_.z = this->MaxSpeed();
    }
  }
  if (stamina_ > 1) {
    stamina_ = 1;
  }
  stamina_ += Clock::Get()->GetTimeSinceLastInSeconds() * 0.1;
}
void logic::Player::Modify(logic::Modifier mod) {

  if (mod.velocity.y > 0) {
    this->airborne_ = true;
  }
  this->velocity_ += mod.velocity;
  if (this->score_ < -(mod.score)) {
    this->score_ = 0;
  }
  else {
    this->score_ += mod.score;
  }
  if (mod.dead) {
    this->dead = true;
  }
  if (mod.slow) {
    this->velocity_ = {0, this->velocity_.y, GameSettings::PlayerSpeed()/4};
    this->bumped_ += 1;
  }
  if (mod.respawn) {
    this->Respawn();
  }
  if (mod.finish) {
    this->finished_ = true;
  }
}
void logic::Player::Respawn() {
  this->score_ -= 10000;
  this->velocity_ = {0, 0, 0};
  this->deaths += 1;
  uint8_t lane = Random::Get().Int(0, GameSettings::Lanes()-1);
  this->SetPosition({2* lane, 5, this->points_[0].z} );
}
float logic::Player::MaxSpeed() { return 0; }

logic::User::User() : logic::Player(glm::vec3(0, 1, 0), glm::vec3(1, 1, 1)) {}

logic::User::User(glm::vec3 pos, glm::vec3 size) : Player(pos, size) {
  this->velocity_ = {0, 0.f, GameSettings::PlayerSpeed()};
}
float logic::User::MaxSpeed() { return GameSettings::PlayerSpeed(); }
void logic::User::Update() {
  this->emp_charge_ += Clock::Get()->GetTimeSinceLastInSeconds() / 17;
  if (this->emp_charge_ > 1) {
    this->emp_charge_ = 1;
  }
  Player::Update();
}

logic::NPC::NPC(glm::vec3 pos) : logic::Player(pos, glm::vec3(.8, 1, .8)) {
  this->velocity_ = {0, 0.f, GameSettings::EnemySpeed()};
}
logic::Modifier logic::NPC::Hit() {
  int direction = Random::Get().Int(0, 1);
  if (direction == 0) {
    this->MoveRight(GameSettings::LaneWidth());
  }
  else {
    this->MoveLeft(GameSettings::LaneWidth());
  }
  return {glm::vec3(0.0, 0, 0.0), -5000.f, false, true, false, false, false};
}

float logic::NPC::MaxSpeed() { return GameSettings::EnemySpeed(); }

void logic::NPC::EMPd(float distance) {
  this->velocity_.z - this->velocity_.z / distance;
}

float logic::KillerNPC::MaxSpeed() { return -GameSettings::EnemySpeed(); }

logic::Modifier logic::KillerNPC::Hit() {
  int direction = Random::Get().Int(0, 1);
  if (direction == 0) {
    this->MoveRight(GameSettings::LaneWidth());
  }
  else {
    this->MoveLeft(GameSettings::LaneWidth());
  }
  return {glm::vec3(0.f,0.f,0.f), 0, true, false, false, false, 0};
}
logic::KillerNPC::KillerNPC(glm::vec3 pos) : logic::Player(pos, glm::vec3(.8, 1, .8)){
    this->velocity_ = {0, 0.f, -GameSettings::EnemySpeed()};
}
void logic::KillerNPC::EMPd(float distance) {
  if (distance < 5) {
    this->dead = true;
  }
}
void logic::KillerNPC::CalcVel() {
  this->velocity_.z = -GameSettings::EnemySpeed();
}
