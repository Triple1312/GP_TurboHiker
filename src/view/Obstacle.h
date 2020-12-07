//
// Created by Phili on 03/12/2020.
//

#ifndef GP_V_OBSTACLE_H
#define GP_V_OBSTACLE_H

#include "model/Obstacle.h"
#include "view/Drawable.hpp"
#include <engine/VertexBufferLayout.h>

namespace view {

class Obstacle : public logic::Obstacle, public view::Drawable {
public:
    Obstacle();
};

} // namespace view


#endif //GP_OBSTACLE_H
