
#ifndef GP_SRC_MODEL_ENTITY_H_
#define GP_SRC_MODEL_ENTITY_H_

#include <deque>
#include <glm/gtx/transform.hpp>
#include <glm/matrix.hpp>
#include <glm/vec4.hpp>
#include <iostream>
#include <memory>

#include "DisignByContract.h"
#include "model/Clock.hpp"
#include "model/GameSettings.h"

/**
 *@brief: an enum that describes at which axis two entities collide;
 */
enum CollissionType {
  NO_COL = false,
  X_COL = true,
  Y_COL = true,
  Z_COL = true
};  // todo beter vector

namespace logic {

class Entity {
 public:
  /**
   * @brief: describes the velocity in every axis
   */
  glm::vec3 velocity_ = glm::vec3(0.0f, 0.0f, 0.0f);

  /**
   *@brief: saves every point of the entity
   * an entity will always be a recengular cube
   */
  std::array<glm::vec3, 8> points_;  // stride is 3

  /**
   * @brief function that checks collision for every axis
   */
  virtual glm::vec3 Collision(std::shared_ptr<Entity>);

  /**
   *@brief returns a pointer to a c-array whinch holds all the points of the
   *entiry
   */
  void *GetPoints();  // returns a pointer to an array of 24 floats

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

  virtual glm::vec3 GetSize();

  virtual glm::vec3 GetPosition();

  virtual void SetPosNoX(float y, float z);

  virtual void MoveForward(float);  // todo bedenk deftige naam

  virtual void MoveBack(float);

  virtual void MoveLeft(float);

  virtual void MoveRight(float);

  virtual void MoveUp(float);

  virtual void MoveX(float);

  virtual void MoveY(float) {}

  virtual void MoveZ(float);

  //virtual void SetPositionBottom(glm::vec3);

  //virtual glm::vec3 GetPositionTop();

  virtual void Display();

 protected:
  Entity() =
  default;  // making it impossible to create which means e_t is never None

  Entity(glm::vec3 pos, glm::vec3 size);
};

}  // namespace logic

#endif  // GP_SRC_MODEL_ENTITY_H_
