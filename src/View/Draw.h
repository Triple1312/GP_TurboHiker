//
// Created by Phili on 12/11/2020.
//

#ifndef GP_DRAW_H
#define GP_DRAW_H

#include <memory>
#include <deque>
#include <utility>
#include <vector>
#include <fstream>
#include <typeinfo>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <glm/vec4.hpp>
#include <glm/matrix.hpp>


#include "../Entity.h"
#include "../Obstacle.h"
#include "../Item.h"
#include "../Player.h"
#include "../Lane.h"
#include "../Vector3.h"

class Draw {
public:
    explicit Draw(sf::RenderWindow& window);

    void DrawEntities(std::deque<std::shared_ptr<Entity>>&);

    void DrawLanes(std::deque<std::shared_ptr<Lane>>&);

    std::shared_ptr<sf::RectangleShape> CalcFace(glm::vec4, glm::vec4, std::uint8_t);

    glm::mat4 GetRotateX(double angle);


private:
    sf::RenderWindow& window;

    float scale = 60;

    float angle = 45; // specified in degrees

    sf::Vector3f blub;

};


#endif //GP_DRAW_H
