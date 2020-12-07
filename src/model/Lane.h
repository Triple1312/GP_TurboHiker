
#ifndef GP_LANE_H
#define GP_LANE_H

#include <deque>
#include <memory>

#include <glm/glm.hpp>

#include "model/Obstacle.h"
#include "model/Player.h" // in theory could have used Entity todo check if Entity better
#include "model/Entity.h"


namespace logic{

struct LaneChunk : public Entity {
    Obstacle obstacle;

    /**
     * @param pos
     * @param size
     */
    LaneChunk(glm::vec3 pos, glm::vec3 size);

    virtual void Display(){ std::cout << "ni wa ik wil" << std::endl;}

    LaneChunk() = default;

};

class Lane : public logic::Entity {
public:
    /*
     * gaan ervanuit dat length 100 is
     *
     */


    /**
     * @param the position of the first lanechunk of the lane
     * @param the amount of lanechunks
     * @param the
     */
//    Lane(glm::vec3, double, glm::vec3);

    Lane(glm::vec3, glm::vec3);

    Lane() = default;

    void Display() override;

private:
    /*
     * stel const length 5
     * positie wordt elke tick herberekend
     * elke tick waarop een lanechunk uit beeld komt wordt er een nieuwe gemaakt
     * moet random obstacle soort hebben
     */
    std::deque<std::shared_ptr<LaneChunk>> lane_chunks;
public:
    //const std::deque<std::shared_ptr<LaneChunk>> &GetLaneChunks() const;

    ///void SetLaneChunks(const std::deque<LaneChunk> &laneChunks);
};

}
#endif //GP_LANE_H
