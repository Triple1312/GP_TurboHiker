#ifndef GP_SRC_MODEL_PLAYER_H_
#define GP_SRC_MODEL_PLAYER_H_

#include <iostream>
#include <deque>
#include <memory>

#include "model/Entity.h"

namespace logic {

class Player : public logic::Entity {
 public:
//  void Jump();
//
//  void Roll();

  //Player(glm::vec4 ,glm::vec4 = glm::vec4(40.f/60.f, 80.f/60.f, 25.f/60.f, 0));

  virtual void Update();

  //void Display();

 public:
  float stamina_{};
  float speed_{}; // todo: pixel per second ?
//  std::uint8_t height_{}; // if the player jumps or rolls this number will change
  float emp_charge_{};
//  glm::vec3 max_speed_{};
//  glm::vec3 curr_acceleration_{};


  Player(glm::vec3 pos, glm::vec3 size) : logic::Entity(pos, size) {};

  void Jump();

  Player() = default;

};

class User : public logic::Player {
 public:
  User();

  User(glm::vec3 pos, glm::vec3 size);

  void EmpCharge(std::deque<std::shared_ptr<Player>> &);

  //virtual void Display(){}
};

class NPC : public logic::Player {
 public:
  explicit NPC(glm::vec3 pos);

  void Display() override {}

  //void Update() override {}

};

}

#endif //GP_SRC_MODEL_PLAYER_H_
