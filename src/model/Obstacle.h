#ifndef GP_SRC_MODEL_OBSTACLE_H_
#define GP_SRC_MODEL_OBSTACLE_H_

#include "Entity.h"

namespace logic {

enum ObstType{ WALL = 1, HORDE = 2, STEP_1 = 3, STEP_2 = 4};

class Obstacle : public Entity {

 public:
  //Obstacle(glm::vec4, glm::vec4);

  Obstacle() = default;

  Obstacle(glm::vec3 pos, glm::vec3 size);

};

/**
 * @note moet een systeem vinden voor meerdere obstakels achter elkaar
 */
class Ramp1 : public Obstacle {
 public:
  explicit Ramp1(glm::vec3 pos);
};

class Ramp2 : public Obstacle {
 public:
  explicit Ramp2(glm::vec3 pos);
};

class OCube : public Obstacle { //todo andere naam geven
 public:
  OCube(glm::vec3 pos, glm::vec3 size);

  OCube() = default;

};

class Horde : public Obstacle {
 public:
  explicit Horde(glm::vec3 pos);
};

class Laser : public Obstacle {

};

class ChunkGone : public Obstacle { //todo geen idee hoe ik dit ga implementeren

};

class Portal : public Obstacle {

};

}

#endif //GP_OBSTACLE_H
