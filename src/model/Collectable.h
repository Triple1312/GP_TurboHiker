//
// Created by phil on 7/29/21.
//

#ifndef GP_SRC_MODEL_COLLECTABLE_H_
#define GP_SRC_MODEL_COLLECTABLE_H_
#include "Obstacle.h"


class Collectable : public logic::Obstacle {
 public:
  explicit Collectable(glm::vec3 pos);

  Modifier Hit() override;

};

#endif  // GP_SRC_MODEL_COLLECTABLE_H_
