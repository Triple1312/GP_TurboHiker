
#ifndef GP_SRC_VIEW_LANE_H_
#define GP_SRC_VIEW_LANE_H_

#include "model/Lane.h"
#include "view/Drawable.hpp"

namespace view {

class Lane : public logic::Lane, public view::Drawable {
 public:
  void Display() override { this->Draw(); }

  Lane(glm::vec3 pos, glm::vec3 size);
};

}  // namespace view

#endif  // GP_SRC_MODEL_LANE_H_
