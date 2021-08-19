//
// Created by Phili on 11/11/2020.
//

#include "Obstacle.h"

logic::OCube::OCube(glm::vec3 pos, glm::vec3 size) : Obstacle(pos, size) {}

logic::Obstacle::Obstacle(glm::vec3 pos, glm::vec3 size)
    : Entity(glm::vec3(pos.x, pos.y + size.y / 2, pos.z), size) {}
logic::Modifier logic::Obstacle::Hit() {
  return {glm::vec3(0,0,0), -1000, false, false, false, true, 0};
}


logic::Ramp1::Ramp1(glm::vec3 pos) : Obstacle(pos, {2, .75, 2}) {}
logic::Ramp2::Ramp2(glm::vec3 pos) : Obstacle(pos, {2, 1.5, 2}) {}
logic::Horde::Horde(glm::vec3 pos) : Obstacle(pos, {1.5, 1.1, 0.3}) {}
logic::Finish::Finish(glm::vec3 pos, int size) : Obstacle(pos, {2* size, 0.5, 0.5}){}
