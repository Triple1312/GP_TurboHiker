#ifndef GP_SRC_MODEL_PLAYER_H_
#define GP_SRC_MODEL_PLAYER_H_

#include <deque>
#include <iostream>
#include <memory>

#include "model/Entity.h"

namespace logic {

class Player : public logic::Entity {
 public:

  virtual ~Player() = default;

  virtual void Update();

  void Modify(Modifier mod);


 public:
  float score_;
  float stamina_{};
  float speed_{};  // todo: pixel per second ?
  bool finished_ = false;
  uint8_t empd_ = 0;
  uint8_t bumped_ = 0;
  float emp_charge_ = 0;
  bool airborne_ = false;
  bool dead = false;
  uint8_t deaths = 0;

  Player(glm::vec3 pos, glm::vec3 size) : logic::Entity(pos, size) {
    this->stamina_ = 1;
  }

  void Jump();

  Player() = default;

  void Bump(float stamina, glm::vec3 dir);

  virtual void CalcVel();

  void Respawn();

  virtual void EMPd(float distance){};

  virtual float MaxSpeed();
};

class User : public logic::Player {
 public:
  User();

  void Update() override;

  virtual ~User() = default;

  User(glm::vec3 pos, glm::vec3 size);

  void EmpCharge(const std::deque<std::shared_ptr<Player>> &);

  float MaxSpeed() override;

};

class NPC : public logic::Player {
 public:
  explicit NPC(glm::vec3 pos);

  virtual ~NPC() = default;

  void Display() override {}

  Modifier Hit() override;

  void EMPd(float distance) override;

  // void Update() override {}
  float MaxSpeed();
};

class KillerNPC : public logic::Player {
  float MaxSpeed();

  Modifier Hit() override;
 public:
  void EMPd(float distance) override;
  virtual ~KillerNPC() = default;
  explicit KillerNPC(glm::vec3 pos);

  void CalcVel() override;
};

}  // namespace logic

#endif  // GP_SRC_MODEL_PLAYER_H_
