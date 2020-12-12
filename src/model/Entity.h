
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

/**
*@brief: an enum that describes at which axis two entities collide;
*/
enum collission_type {no_col = false, x_col = true, y_col = true, z_col = true }; //todo beter vector

namespace logic {

class Entity {
public:
    /**
    * @brief: describes the velocity in every axis
    */
    glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);


    /**
    *@brief: saves every point of the entity
    * an entity will always be a recengular cube
    */
    float points[24]; // stride is 3


    /**
    * @brief function that checks collision for every axis
    */
    virtual glm::vec3 Collision(std::shared_ptr<Entity>);

    /**
    *@brief returns a pointer to a c-array whinch holds all the points of the entiry
    */
    void *GetPoints(); //returns a pointer to an array of 24 floats

    /**
    *@brief returns the center point of the entity
    */
    virtual glm::vec4 GetCenter();
    
    /**
    *@brief moves the entity to a position with as position the given point
    *@idk the center position used to set the position of every point
    */
    virtual void SetPosition(glm::vec3);

    virtual void SetPosition(glm::vec3 pos, glm::vec3 size);

     
    virtual glm::vec3 GetPosition();

    virtual void SetPosNoX(float y, float z);

    virtual void MoveForward(float); // todo bedenk deftige naam

    virtual void MoveBack(float);

    virtual void MoveLeft(float);

    virtual void MoveRight(float);

    virtual void MoveUp(float);

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
