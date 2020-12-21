//
// Created by Phili on 11/11/2020.
//

#include "Player.h"

//void logic::Player::Jump() {
//  this->height_ = 80;
//}
//
//void logic::Player::Roll() {
//  this->height_ = 40;
//}

void logic::User::EmpCharge(std::deque<std::shared_ptr<Player>> &players) {
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
  velocity_.y = velocity_.y + Clock::Get()->GetTimeSinceLastInSeconds() * -1.0;
//  auto t = Clock::Get()->GetTimeSinceLastInSeconds();
//  std::cout << velocity_.y << " || " << t << std::endl;
  this->MoveRight(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.x);
  this->MoveUp(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.y);
  this->MoveForward(Clock::Get()->GetTimeSinceLastInSeconds() * this->velocity_.z);
  //std::cout << Clock::Get()->TimeSinceLast() << std::endl;
}

logic::User::User() : logic::Player(glm::vec3(0, 1, 0),
                                    glm::vec3(1, 1, 1)) {

}

logic::User::User(glm::vec3 pos, glm::vec3 size) : Player(pos, size) {
  this->velocity_ = {0, 0.f, 2.f};
}
logic::NPC::NPC(glm::vec3 pos) : logic::Player(pos,
                                 glm::vec3(.8, .8, .8)){
  this->velocity_ = {0, 0.f, 2.f};

}
