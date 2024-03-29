#ifndef GP_SRC_MODEL_FACTORY_H_
#define GP_SRC_MODEL_FACTORY_H_

#include "model/Lane.h"
#include "model/Obstacle.h"
#include "model/Player.h"
#include "model/World.h"

namespace logic {

class Factory {
 public:
  Factory(Factory &) = delete;

  virtual ~Factory() { delete instance_; }

  static logic::Factory *Get() {
    return instance_;
  }

  virtual std::shared_ptr<logic::NPC> MakeNPC(glm::vec3 pos) {
    return std::make_shared<logic::NPC>(pos);
  }

  virtual std::shared_ptr<logic::KillerNPC> MakeKillerNPC(glm::vec3 pos){
    return std::make_shared<logic::KillerNPC>(pos);
  }

  virtual std::shared_ptr<logic::User> MakeUser() {
    return std::make_shared<logic::User>();
  }

  virtual std::shared_ptr<logic::User> MakeUser(glm::vec3 pos,
                                                glm::vec3 size) = 0;

  virtual std::shared_ptr<logic::Obstacle> MakeObstacle(
      glm::vec3 pos, logic::ObstType obst_type) = 0;

  virtual std::shared_ptr<logic::Lane> MakeLane(glm::vec3 pos,
                                                glm::vec3 size) = 0;

  virtual std::shared_ptr<logic::OCube> MakeOCube(
      std::shared_ptr<logic::Entity> entity) = 0;

  virtual std::shared_ptr<logic::OCube> MakeOCube() {
    return std::make_shared<logic::OCube>();
  }


  virtual std::shared_ptr<logic::Scoreboard> MakeScoreBoard(
      std::shared_ptr<logic::Player>) = 0;

 protected:
  static logic::Factory *instance_;

  Factory() = default;
};

}  // namespace logic

#endif  // GP_SRC_MODEL_FACTORY_H_
