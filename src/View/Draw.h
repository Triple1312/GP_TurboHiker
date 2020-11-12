//
// Created by Phili on 12/11/2020.
//

#ifndef GP_DRAW_H
#define GP_DRAW_H

#include <memory>
#include <deque>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../Entity.h"
#include "../Obstacle.h"
#include "../Item.h"
#include "../Player.h"

class Draw {
public:
    explicit Draw(sf::RenderWindow& window) : window(window) {}

    void DrawEntities(std::deque<Entity>);




private:
    sf::RenderWindow& window;

};


#endif //GP_DRAW_H
