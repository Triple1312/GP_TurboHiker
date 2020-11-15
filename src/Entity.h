
#ifndef GP_ENTITY_H
#define GP_ENTITY_H

#include <memory>
#include <iostream>

#include "Vector3.h"
#include "DisignByContract.h"

//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>

enum entity_type{obstacle, player, e_item};

class Entity {
public:
    ppp::Vec3F size;
    ppp::Vec3F pos;

    void MoveUp(double);

    void MoveDown(double);

    void MoveRight(double);

    void MoveLeft(double);

    bool Collision(std::shared_ptr<Entity>);

    entity_type& GetEntityType();

    void SetPosTo(ppp::Vec3F);

    ppp::Vec3F GetCenter();

    ppp::Vec3F GetCenterPos();

    void SetCenterPos(ppp::Vec3F p);

    ppp::Vec3F GetPos();

protected:
    Entity() = default; //making it impossible to create which means e_t is never None

    void SetEntityType(entity_type);

//    std::shared_ptr<sf::RectangleShape> shape;

private:
    entity_type e_t ;


};

#endif //GP_ENTITY_H
