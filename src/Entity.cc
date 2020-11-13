//
// Created by Phili on 09/11/2020.
//

#include "Entity.h"

void Entity::MoveUp(double offset) {
    pos.y += offset;
}

void Entity::MoveDown(double offset) {
    pos.y -= offset;
}

void Entity::MoveRight(double offset) {
    pos.x += offset;
}

void Entity::MoveLeft(double offset) {
    pos.x -= offset;
}

bool Entity::Collision(std::shared_ptr<Entity> enti) {
    if (this->pos.y == 0) { // where there are holes in the lane
        return true;
    }
    if (this->pos.y - this->size.y > enti->size.y ) {
        return false;
    }
    if (enti->pos.y - enti->size.y > this->size.y ) {
        return false;
    }
    return true;
}

entity_type &Entity::GetEntityType() {
    return this->e_t;
}

void Entity::SetEntityType(entity_type type) {
    this->e_t = type;
}

std::shared_ptr<sf::RectangleShape> Entity::GetShape() {
    return this->shape;
}

void Entity::SetCenterTo(sf::Vector2f to) {
     sf::Vector2f c = GetCenter();
//     float x = to.x + this->shape->getSize().x/2.f;
//     this->shape->setPosition()

     auto f = sf::Vector2f (to.x - this->shape->getSize().x, to.y - this->shape->getSize().y);
     this->shape->setPosition(sf::Vector2f (to.x - this->shape->getSize().x/2.f, to.y - this->shape->getSize().y/2.f));
}

sf::Vector2f Entity::GetCenter() {
    return sf::Vector2f(this->shape->getPosition() + this->shape->getSize()/2.f);
}
