//
// Created by Phili on 11/11/2020.
//

#include "Player.h"

void logic::Player::Jump() {
  this->height = 80;
}

void logic::Player::Roll() {
  this->height = 40;
}

void logic::Player::EmpCharge(std::deque<std::shared_ptr<Player>> &players) {
  for (const std::shared_ptr<Player>& i : players) {
    if (i.get() != this) {
      i->speed = i->speed / 2;
    }
  }
}

void logic::Player::Update() {
  this->MoveRight(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.x);
  this->MoveUp(Clock::Get()->GetTimeSinceLastInSeconds() * velocity_.y);
  this->MoveForward(Clock::Get()->GetTimeSinceLastInSeconds() * this->velocity_.z);
  //std::cout << Clock::Get()->TimeSinceLast() << std::endl;
}

logic::User::User() : logic::Player(glm::vec3(0, 1, 0),
                                    glm::vec3(1, 1, 1)) {

}

logic::User::User(glm::vec3 pos, glm::vec3 size) : Player(pos, size) {

}
