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

logic::User::User() : logic::Player(glm::vec3(0, 1, 0),
                                    glm::vec3(0.5, 1.7, 0.3)){

}
