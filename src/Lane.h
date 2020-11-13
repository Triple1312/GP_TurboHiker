//
// Created by Phili on 11/11/2020.
//

#ifndef GP_LANE_H
#define GP_LANE_H

#include <deque>
#include <memory>

#include <SFML/Window.hpp>

#include "Obstacle.h"
#include "Player.h" // in theory could have used Entity todo check if Entity better

class Lane {
public:
    /*
     * gaan ervanuit dat length 100 is
     *
     */
    struct LaneChunk {
        std::shared_ptr<sf::RectangleShape> shape;
        Obstacle obstacle;

        LaneChunk();

        std::uint8_t GetCenterX();

        std::uint8_t GetCenterY();

        sf::Vector2f GetCenter();

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

    std::uint8_t GetCenterX();

    std::uint8_t GetCenterY();
};


#endif //GP_LANE_H
