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

Player::Player(sf::Vector3f pos) {
    this->size = sf::Vector3i(50, 70, 30);
    this->SetEntityType(player);
    this->pos = pos;
    this->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(50.f, 70.f));
    this->shape->setFillColor(sf::Color::Blue);
}
