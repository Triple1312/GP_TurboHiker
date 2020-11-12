//
// Created by Phili on 11/11/2020.
//

#ifndef GP_LANE_H
#define GP_LANE_H

#include <deque>
#include <memory>

#include "Obstacle.h"
#include "Player.h" // in theory could have used Entity todo check if Entity better

class Lane {
public:


private:
    int height;
    std::deque<Obstacle> obstacles;

};


#endif //GP_LANE_H
