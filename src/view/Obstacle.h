//
// Created by Phili on 03/12/2020.
//

#ifndef GP_V_OBSTACLE_H
#define GP_V_OBSTACLE_H

#include "model/Obstacle.h"
#include "view/Drawable.hpp"
#include <engine/VertexBufferLayout.h>

namespace view {

class Ramp : public logic::Ramp , public view::Drawable{

    };

    class OCube : public logic::OCube , public view::Drawable { //todo andere naam geven
    public:
        OCube();

        void Display() override;
    };

    class Laser : public logic::Laser , public view::Drawable {

    };

    class ChunkGone : public logic::ChunkGone , public view::Drawable { //todo geen idee hoe ik dit ga implementeren

    };

    class Portal : public logic::Portal , public view::Drawable {

    };
} // namespace view


#endif //GP_OBSTACLE_H
