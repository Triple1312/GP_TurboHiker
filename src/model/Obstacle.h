//
// Created by Phili on 11/11/2020.
//

#ifndef GP_AOBSTACLE_H
#define GP_AOBSTACLE_H

#include "Entity.h"

namespace logic {

class Obstacle : public Entity {

 public:
  //Obstacle(glm::vec4, glm::vec4);

  Obstacle() = default;

  Obstacle(glm::vec3 pos, glm::vec3 size);

};

/**
 * @note moet een systeem vinden voor meerdere obstakels achter elkaar
 */
class Ramp : public Obstacle {

};

class OCube : public Obstacle { //todo andere naam geven
 public:
  OCube(glm::vec3 pos, glm::vec3 size);

  OCube() = default;

};

class Laser : public Obstacle {

};

class ChunkGone : public Obstacle { //todo geen idee hoe ik dit ga implementeren

};

class Portal : public Obstacle {

};

}

#endif //GP_OBSTACLE_H
