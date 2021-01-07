
#include "Player.h"

void logic::User::EmpCharge(const std::deque<std::shared_ptr<Player>> &players) {
  auto temp = this->GetPosition();
  for (const std::shared_ptr<Player>& i : players) {
    if (i.get() != (Player*)this) {
      float distance = glm::length(i->GetPosition() - temp);
      i->speed_ = i->speed_ /distance;
      i->stamina_ = i->stamina_ / distance;
    }
  }
}

void logic::Player::Update() {
  velocity_.y = velocity_.y + Clock::Get()->GetTimeSinceLastInSeconds() * -2.0;
//  auto t = Clock::Get()->GetTimeSinceLastInSeconds();
//  std::cout << velocity_.y << " || " << t << std::endl;
  this->MoveRight(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.x);
  this->MoveUp(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.y);
  this->MoveForward(Clock::Get()->GetTimeSinceLastInSeconds() * this->velocity_.z);
  //std::cout << Clock::Get()->TimeSinceLast() << std::endl;
  this->CalcVel();
}
void logic::Player::Jump() {
  if (airborne_){return;}
  airborne_ = true;
  this->velocity_.y = GameSettings::JumpHeight();
}
void logic::Player::Bump(float stamina, glm::vec3 dir) {
  if (stamina > stamina_) {
    this->velocity_.z = this->velocity_.z * stamina_/stamina;
    this->stamina_ = 0;
    //todo verplaatsen

  }
  else if (stamina == 0) {
    // todo delete ?
    std::cout << "ha";
  }
  else {
    this->velocity_.z = this->velocity_.z * stamina_/stamina;
    this->stamina_ = stamina_ - stamina;
  }
}

void logic::Player::CalcVel() {
  if (velocity_.z > 2 ) {
    velocity_.z -= Clock::Get()->GetTimeSinceLastInSeconds() * 0.2;
    stamina_ += Clock::Get()->GetTimeSinceLastInSeconds() * 0.2;
    if (velocity_.z < GameSettings::PlayerSpeed()) {velocity_.z = GameSettings::PlayerSpeed();}

  }
  else if ( velocity_.z < GameSettings::PlayerSpeed() && stamina_ != 0) {
    velocity_.z += Clock::Get()->GetTimeSinceLastInSeconds() * 0.5;
    stamina_-= Clock::Get()->GetTimeSinceLastInSeconds() * 0.1;
    if (velocity_.z > GameSettings::PlayerSpeed()) {velocity_.z = GameSettings::PlayerSpeed();}
  }
  if (stamina_ > 1) { stamina_ = 1;}
  stamina_+= Clock::Get()->GetTimeSinceLastInSeconds() * 0.1;
}

logic::User::User() : logic::Player(glm::vec3(0, 1, 0),
                                    glm::vec3(1, 1, 1)) {

}

logic::User::User(glm::vec3 pos, glm::vec3 size) : Player(pos, size) {
  this->velocity_ = {0, 0.f, GameSettings::PlayerSpeed()};
}
logic::NPC::NPC(glm::vec3 pos) : logic::Player(pos,
                                 glm::vec3(.8, .8, .8)){
  this->velocity_ = {0, 0.f, GameSettings::PlayerSpeed()};

}
