
#ifndef GP_ENTITY_H
#define GP_ENTITY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Entity {
public:
    sf::Vector2f size;
    sf::Vector2f pos;

    void MoveUp(double);

    void MoveDown(double);

    void MoveRight(double);

    void MoveLeft(double);
};

#endif //GP_ENTITY_H
