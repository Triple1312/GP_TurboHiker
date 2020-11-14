//
// Created by Phili on 11/11/2020.
//

#ifndef GP_LANE_H
#define GP_LANE_H

#include <deque>
#include <memory>

//#include <SFML/Window.hpp>

#include "Obstacle.h"
#include "Player.h" // in theory could have used Entity todo check if Entity better

class Lane {
public:
    /*
     * gaan ervanuit dat length 100 is
     *
     */
    struct LaneChunk : public Entity{
        Obstacle obstacle;

        LaneChunk();



        LaneChunk(ppp::Vec3F, ppp::Vec3F = ppp::Vec3F(50, 1, 100));

    };

    Lane(double, double = 100);

private:
    int height;
    /*
     * stel const length 5
     * positie wordt elke tick herberekend
     * elke tick waarop een lanechunk uit beeld komt wordt er een nieuwe gemaakt
     * moet random obstacle soort hebben
     */
    std::deque<std::shared_ptr<LaneChunk>> lane_chunks;
public:
    const std::deque<std::shared_ptr<LaneChunk>> &GetLaneChunks() const;

    ///void SetLaneChunks(const std::deque<LaneChunk> &laneChunks);
};


#endif //GP_LANE_H
