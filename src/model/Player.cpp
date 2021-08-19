
#include "Player.h"

#include <Utils/Random.hpp>

void logic::User::EmpCharge(
  const std::deque<std::shared_ptr<Player>>& players) {
  this->velocity_ = {0, 0, 0};
  auto temp = this->GetPosition();
  for (const std::shared_ptr<Player>& i : players) {
    if (i.get() != (Player*)this) {
      float distance = glm::length(i->GetPosition() - temp);
      i->speed_ = i->speed_ / distance;
      i->stamina_ = i->stamina_ / distance;
    }
  }
}

void logic::Player::Update() {
  this->score_ += Clock::Get()->GetTimeSinceLastInMilliSeconds();
  velocity_.y = velocity_.y + Clock::Get()->GetTimeSinceLastInSeconds() * -2.0;
  //  auto t = Clock::Get()->GetTimeSinceLastInSeconds();
  //  std::cout << velocity_.y << " || " << t << std::endl;
  this->MoveRight(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.x);
  this->MoveUp(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.y);
  this->MoveForward(Clock::Get()->GetTimeSinceLastInSeconds() *
                    this->velocity_.z);
  // std::cout << Clock::Get()->TimeSinceLast() << std::endl;
  this->CalcVel();
  this->score_ += Clock::Get()->GetTimeSinceLastInSeconds() * 100;

  if (this->GetCenter().y < -3) {
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
  if (stamina > stamina_) {
    this->velocity_.z = this->velocity_.z * stamina_ / stamina;
    this->stamina_ = 0;
    // todo verplaatsen

  } else if (stamina == 0) {
    // todo delete ?
    std::cout << "ha";
  } else {
    this->velocity_.z = this->velocity_.z * stamina_ / stamina;
    this->stamina_ = stamina_ - stamina;
  }
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
  this->score_ += mod.score;
  if (mod.die) { this->Respawn();}
}
void logic::Player::Respawn() {
  this->score_ -= 100;
  this->velocity_ = {0, 0, 0};
  this->SetPosition({2, 10, this->points_[0].z} );
}
float logic::Player::MaxSpeed() { return 0; }

logic::User::User() : logic::Player(glm::vec3(0, 1, 0), glm::vec3(1, 1, 1)) {}

logic::User::User(glm::vec3 pos, glm::vec3 size) : Player(pos, size) {
  this->velocity_ = {0, 0.f, GameSettings::PlayerSpeed()};
}
float logic::User::MaxSpeed() { return GameSettings::PlayerSpeed(); }

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
  return {glm::vec3(0.0, -10, -1.0), -50.f, true};
}

float logic::NPC::MaxSpeed() { return GameSettings::EnemySpeed(); }