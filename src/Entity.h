
#ifndef GP_ENTITY_H
#define GP_ENTITY_H

#include <memory>
#include <iostream>
#include <deque>

//#include "Vector3.h"
#include "DisignByContract.h"
#include "../libs/glm-0.9.9.8/glm/glm/vec4.hpp"
#include "../libs/glm-0.9.9.8/glm/glm/matrix.hpp"
#include "../libs/glm-0.9.9.8/glm/glm/gtx/transform.hpp"

//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>

enum entity_type{obstacle, player, e_item};

class Entity {
public:
    glm::vec4 size;
    glm::vec4 pos;

    void MoveUp(double);

    void MoveDown(double);

    void MoveRight(double);

    void MoveLeft(double);

    bool Collision(std::shared_ptr<Entity>);

    entity_type& GetEntityType();

    void SetPosTo(glm::vec4);

    glm::vec4 GetCenter();

    glm::vec4 GetCenterPos();

    void SetCenterPos(glm::vec4 p);

    glm::vec4 GetPos();

    std::deque<glm::vec4> GetAllPoints();

    std::deque<glm::vec4> GetFace(std::uint8_t);

protected:
    Entity() = default; //making it impossible to create which means e_t is never None

    void SetEntityType(entity_type);

//    std::shared_ptr<sf::RectangleShape> shape;

private:
    entity_type e_t ;


};

#endif //GP_ENTITY_H
