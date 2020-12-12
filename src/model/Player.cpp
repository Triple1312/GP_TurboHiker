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

void logic::Player::EmpCharge(std::deque<std::shared_ptr<Player>>& players) {
    for ( std::shared_ptr<Player> i : players) {
        if ( i.get() != this) {
            i->speed = i->speed/2;
        }
    }
}

void logic::Player::Update() {
    this->MoveRight(Clock::Get()->GetTimeSinceLastInSeconds() * velocity.x);
    this->MoveUp(Clock::Get()->GetTimeSinceLastInSeconds() * velocity.y);
    this->MoveForward(Clock::Get()->GetTimeSinceLastInSeconds() * this->velocity.z);
    //std::cout << Clock::Get()->TimeSinceLast() << std::endl;
}

logic::User::User() : logic::Player(glm::vec3(0, 1, 0),
                                    glm::vec3(1, 1, 1)){

}

logic::User::User(glm::vec3 pos, glm::vec3 size) : Player(pos, size) {

}
