
#ifndef GP_VWORLD_H
#define GP_VWORLD_H

#include "model/World.h"

namespace view {

class World : public logic::World {
public:

    explicit World(std::uint8_t lanes) : logic::World(lanes) {  }

};

}



#endif //GP_SRC_MODEL_WORLD_H_
