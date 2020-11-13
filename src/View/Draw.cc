//
// Created by Phili on 12/11/2020.
//

#include "Draw.h"

void Draw::DrawEntities(std::deque<std::shared_ptr<Entity>>& entities) {
    for ( auto e : entities) {
        window.draw(  *e->GetShape());
    }
}

void Draw::DrawLanes(std::deque<std::shared_ptr<Lane>>& lanes) {
    for ( auto l : lanes ) {
        for ( auto c : l->GetLaneChunks() ) {
            window.draw(*c->shape);
        }
    }
}

