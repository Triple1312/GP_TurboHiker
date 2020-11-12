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
