#ifndef GP_SRC_MODEL_PLAYER_H_
#define GP_SRC_MODEL_PLAYER_H_

#include <deque>
#include <iostream>
#include <memory>

#include "model/Entity.h"

namespace logic {

class Player : public logic::Entity {
 public:
  //  void Jump();
  //
  //  void Roll();

  // Player(glm::vec4 ,glm::vec4 = glm::vec4(40.f/60.f, 80.f/60.f, 25.f/60.f,
  // 0));

  virtual ~Player() = default;

  virtual void Update();

  void Modify(Modifier mod);

  // void Display();

 public:
  float score_;
  float stamina_{};
  float speed_{};  // todo: pixel per second ?
  bool finished_ = false;
  //  std::uint8_t height_{}; // if the player jumps or rolls this number will
  //  change
  float emp_charge_{};
  bool airborne_ = false;
  bool dead = false;
  //  glm::vec3 max_speed_{};
  //  glm::vec3 curr_acceleration_{};

  Player(glm::vec3 pos, glm::vec3 size) : logic::Entity(pos, size) {
    this->stamina_ = 1;
  }

  void Jump();

  Player() = default;

  void Bump(float stamina, glm::vec3 dir);

  void CalcVel();

  void Respawn();

  virtual float MaxSpeed();
};

class User : public logic::Player {
 public:
  User();

  virtual ~User() = default;

  User(glm::vec3 pos, glm::vec3 size);

  void EmpCharge(const std::deque<std::shared_ptr<Player>> &);

  float MaxSpeed() override;

  // virtual void Display(){}
};

class NPC : public logic::Player {
 public:
  explicit NPC(glm::vec3 pos);

  virtual ~NPC() = default;

  void Display() override {}

  Modifier Hit() override;

  // void Update() override {}
  float MaxSpeed();
};

class KillerNPC : public logic::Player {
  float MaxSpeed();



  Modifier Hit() override;
 public:
  virtual ~KillerNPC() = default;
  explicit KillerNPC(glm::vec3 pos);
};

}  // namespace logic

#endif  // GP_SRC_MODEL_PLAYER_H_
