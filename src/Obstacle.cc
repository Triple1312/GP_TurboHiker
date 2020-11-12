//
// Created by Phili on 11/11/2020.
//

#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector3i s, sf::Vector3f p) {
    this->SetEntityType(obstacle);
    this->size = s;
    this->pos = p;
}
