//
// Created by Phili on 03/12/2020.
//

#ifndef GP_SRC_VIEW_OBSTACLE_H_
#define GP_SRC_VIEW_OBSTACLE_H_

#include <engine/VertexBufferLayout.h>

#include "model/Obstacle.h"
#include "view/Drawable.hpp"

namespace view {

class Ramp1 : public logic::Ramp1, public view::Drawable {
 public:
  explicit Ramp1(glm::vec3 pos);

  void Display() override;
};

class Ramp2 : public logic::Ramp2, public view::Drawable {
 public:
  explicit Ramp2(glm::vec3 pos);

  void Display() override;
};

class OCube : public logic::OCube,
              public view::Drawable {  // todo andere naam geven
 public:
  explicit OCube(glm::vec3 pos);

  void Display() override;
};

class Laser : public logic::Laser, public view::Drawable {};

class ChunkGone
    : public logic::ChunkGone,
      public view::Drawable {  // todo geen idee hoe ik dit ga implementeren
};

class Portal : public logic::Portal, public view::Drawable {};

class Horde : public logic::Horde, public view::Drawable {
 public:
  explicit Horde(glm::vec3 pos);

  void Display() override;
};
}  // namespace view

#endif  // GP_OBSTACLE_H
