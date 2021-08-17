//
// Created by phil on 8/16/21.
//

#ifndef GP_SRC_VIEW_COLLECTABLE_H_
#define GP_SRC_VIEW_COLLECTABLE_H_

#include "Drawable.hpp"
#include "model/Collectable.h"

namespace view {

class Collectable : public logic::Collectable, public view::Drawable {
 public:

  explicit Collectable(glm::vec3 pos);

  void Display() override;

};

}

#endif  // GP_SRC_VIEW_COLLECTABLE_H_
