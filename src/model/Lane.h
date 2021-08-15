#ifndef GP_SRC_MODEL_LANE_H_
#define GP_SRC_MODEL_LANE_H_

#include <deque>
#include <glm/glm.hpp>
#include <memory>

#include "model/Entity.h"
#include "model/Obstacle.h"
#include "model/Player.h"  // in theory could have used Entity todo check if Entity better

namespace logic {

class Lane : public logic::Entity {
 public:
  Lane(glm::vec3, glm::vec3);

  Lane() = default;
};

}  // namespace logic
#endif  // GP_SRC_MODEL_LANE_H_
