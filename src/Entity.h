
#ifndef GP_ENTITY_H
#define GP_ENTITY_H

#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum entity_type{obstacle, player, e_item};

class Entity {
public:
    sf::Vector3i size;
    sf::Vector3f pos;

    void MoveUp(double);

    void MoveDown(double);

    void MoveRight(double);

    void MoveLeft(double);

    bool Collision(std::shared_ptr<Entity>);

    entity_type& GetEntityType();

    std::shared_ptr<sf::RectangleShape> GetShape();

protected:
    Entity() = default; //making it impossible to create which means e_t is never None

    void SetEntityType(entity_type);

    std::shared_ptr<sf::RectangleShape> shape;

private:
    entity_type e_t ;






};

#endif //GP_ENTITY_H
