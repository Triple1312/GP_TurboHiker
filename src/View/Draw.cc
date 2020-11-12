//
// Created by Phili on 12/11/2020.
//

#include "Draw.h"

void Draw::DrawEntities(std::deque<Entity> entities) {
    for ( Entity& e : entities) {
        window.draw(e.GetShape());
    }
}

