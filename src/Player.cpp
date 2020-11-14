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

Player::Player( ppp::Vec3F pos) {
    this->size = ppp::Vec3F (50, 70, 30);
    this->SetEntityType(player);
    this->pos = pos;
//    this->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(50.f, 70.f));
//    this->shape->setFillColor(sf::Color::Blue);
//    this->shape->setPosition(pos.x, pos.y);
}

void Player::SetPosition(ppp::Vec3F pos) {
    ///this->shape->setPosition(pos.x, pos.y);
}

void Player::EmpCharge(std::deque<std::shared_ptr<Player>>& players) {
    for ( std::shared_ptr<Player> i : players) {
        if ( i.get() != this) {
            i->speed = i->speed/2;
        }
    }
}
