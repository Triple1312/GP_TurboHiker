
#ifndef GP_ENTITY_H
#define GP_ENTITY_H

#include <memory>
#include <iostream>
#include <deque>

#include "DisignByContract.h"
#include <glm/vec4.hpp>
#include <glm/matrix.hpp>
#include <glm/gtx/transform.hpp>
#include "model/Clock.hpp"

enum collission_type {no_col = false, x_col = true, y_col = true, z_col = true };

namespace logic {

class Entity {
public:

    glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);

    float points[24]; // stride is 3



    virtual collission_type Collision(std::shared_ptr<Entity>);

    void *GetPoints(); //returns a pointer to an array of 24 floats

    virtual glm::vec4 GetCenter();

    virtual void SetPosition(glm::vec3);

    virtual void SetPosition(glm::vec3 pos, glm::vec3 size);

    virtual glm::vec3 GetPosition();

    virtual void SetPosNoX(float y, float z);

    virtual void MoveForward(float); // todo bedenk deftige naam

    virtual void MoveBack(float);

    virtual void MoveLeft(float);

    virtual void MoveRight(float);

    virtual void MoveX(float);

    virtual void MoveY(float) {  }

    virtual void MoveZ(float);

    virtual void SetPositionBottom(glm::vec3);

    virtual glm::vec3 GetPositionTop();

    virtual void Display();

protected:
    Entity() = default; //making it impossible to create which means e_t is never None

    Entity(glm::vec3 pos, glm::vec3 size);


};

} // model

#endif //GP_ENTITY_H
