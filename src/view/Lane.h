
#ifndef GP_SRC_VIEW_LANE_H_
#define GP_SRC_VIEW_LANE_H_

#include "view/Drawable.hpp"
#include "model/Lane.h"

namespace view {

class LaneChunk : public logic::LaneChunk , public view::Drawable {
public:

    void Display() override { this->Draw(); }

    //LaneChunk();

    LaneChunk(glm::vec3 pos, glm::vec3 size);


    };







}



#endif //GP_SRC_MODEL_LANE_H_
