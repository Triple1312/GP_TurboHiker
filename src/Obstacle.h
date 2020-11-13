//
// Created by Phili on 11/11/2020.
//

#ifndef GP_OBSTACLE_H
#define GP_OBSTACLE_H

#include "Entity.h"


class Obstacle : public Entity {
public:
    Obstacle(sf::Vector3i, sf::Vector3f );

    Obstacle() = default;


};


#endif //GP_OBSTACLE_H
