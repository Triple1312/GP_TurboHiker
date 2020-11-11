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
