//
// Created by Phili on 11/11/2020.
//

#include "Obstacle.h"

Obstacle::Obstacle(ppp::Vec3F s, ppp::Vec3F p) {
    this->SetEntityType(obstacle);
    this->size = s;
    this->pos = p;
}
