#ifndef GP_SRC_MODEL_OBSTACLE_H_
#define GP_SRC_MODEL_OBSTACLE_H_

#include "Entity.h"

namespace logic {

enum ObstType { WALL = 1, HORDE = 2, STEP_1 = 3, STEP_2 = 4, COLLECTABLE = 5, FINISH = 6};

/**
 * @brief class that defines objects that are static in the world
 */
class Obstacle : public Entity {
 public:

  Obstacle() = default;

  Obstacle(glm::vec3 pos, glm::vec3 size);

  virtual ~Obstacle() = default;

  virtual Modifier Hit() override;
};

/**
 * @brief: old obstacle , unused now
 */
class Ramp1 : public Obstacle {
 public:
  explicit Ramp1(glm::vec3 pos);

  virtual ~Ramp1()  = default;
};

/**
 * @brief: old obstacle , unused now
 */
class Ramp2 : public Obstacle {
 public:
  explicit Ramp2(glm::vec3 pos);
};

class OCube : public Obstacle {
 public:
  OCube(glm::vec3 pos, glm::vec3 size);

  OCube() = default;

  virtual ~OCube() = default;
};

class Horde : public Obstacle {
 public:
  explicit Horde(glm::vec3 pos);

  virtual ~Horde() = default;
};

class Finish : public Obstacle {
 public:
  explicit Finish( glm::vec3 pos , int size);

  virtual ~Finish() = default;

  Modifier Hit() override;
};

}  // namespace logic

#endif  // GP_OBSTACLE_H
