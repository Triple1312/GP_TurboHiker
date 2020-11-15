//
// Created by Phili on 12/11/2020.
//

#include "Draw.h"

void Draw::DrawEntities(std::deque<std::shared_ptr<Entity>>& entities) {
    for ( auto e : entities) {
        sf::RectangleShape rect(sf::Vector2f(e->size.x * scale, e->size.z * scale));
        rect.setPosition(e->pos.x * scale, e->pos.z * scale);
        rect.setFillColor(sf::Color::Blue);
        window.draw(rect);
    }
}

void Draw::DrawLanes(std::deque<std::shared_ptr<Lane>>& lanes) {
    for ( auto l : lanes ) {
        auto a = *l;
        for ( auto c : l->GetLaneChunks() ) {
            sf::RectangleShape rect(sf::Vector2f(c->size.x * scale, c->size.z * scale));
            rect.setPosition(c->pos.x * scale, c->pos.z * scale);
            rect.setFillColor(sf::Color::Red);
            rect.setOutlineColor(sf::Color::White);
            rect.setOutlineThickness(2);
            window.draw(rect);
        }
    }
}

