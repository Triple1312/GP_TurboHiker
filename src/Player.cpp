//
// Created by Phili on 11/11/2020.
//

#include "Player.h"

void Player::Jump() {
    this->height = 80;
}

void Player::Roll() {
    this->height = 40;
}

Player::Player( glm::vec4 pos, glm::vec4 size) {
    this->size = size;
    this->SetEntityType(player);
    this->pos = pos;
}

void Player::SetPosition(glm::vec4 pos) {
    this->pos = pos;
}

void Player::EmpCharge(std::deque<std::shared_ptr<Player>>& players) {
    for ( std::shared_ptr<Player> i : players) {
        if ( i.get() != this) {
            i->speed = i->speed/2;
        }
    }
}
