#ifndef GP_SRC_VIEW_FACTORY_H_
#define GP_SRC_VIEW_FACTORY_H_

#include <memory>

#include "model/Factory.h"
#include "view/Collectable.h"
#include "view/Lane.h"
#include "view/Obstacle.h"
#include "view/Player.h"
#include "view/Scoreboard.h"

namespace view {

class Factory : public logic::Factory {
 public:
  unsigned int lanechunknr_ = 0;

  ~Factory() override { delete instance_; }

  std::shared_ptr<logic::Obstacle> MakeObstacle(
      glm::vec3 pos, logic::ObstType obst_type) override {
    if (obst_type == logic::WALL) {
      return std::make_shared<view::OCube>(pos);
    } else if (obst_type == logic::HORDE) {
      return std::make_shared<view::Horde>(pos);
    } else if (obst_type == logic::STEP_1) {
      return std::make_shared<view::Ramp1>(pos);
    } else if (obst_type == logic::STEP_2) {
      return std::make_shared<view::Ramp2>(pos);
    } else if (obst_type == logic::COLLECTABLE) {
      return std::make_shared<view::Collectable>(pos);
    } else if (obst_type == logic::FINISH) {
      return std::make_shared<view::Finish>(pos, 7);
    }
    return NULL;
  }

  std::shared_ptr<logic::Lane> MakeLane(glm::vec3 pos,
                                        glm::vec3 size) override {
    return std::make_shared<Lane>(pos, size);
  }

  std::shared_ptr<logic::NPC> MakeNPC(glm::vec3 pos) override {
    return std::make_shared<NPC>(pos);
  }

  std::shared_ptr<logic::KillerNPC> MakeKillerNPC(glm::vec3 pos) override {
    return std::make_shared<view::KillerNPC>(pos);
  }

  std::shared_ptr<logic::User> MakeUser(glm::vec3 pos,
                                        glm::vec3 size) override {
    return std::make_shared<User>(pos, size);
  }

  std::shared_ptr<logic::OCube> MakeOCube(
      std::shared_ptr<logic::Entity> entity) override {
    return std::make_shared<OCube>(entity->GetPosition());
  }

  std::shared_ptr<logic::OCube> MakeOCube() override {
    return std::make_shared<OCube>(glm::vec3(0.f));
  }

  std::shared_ptr<logic::Scoreboard> MakeScoreBoard(
      std::shared_ptr<logic::Player> player) override {
    return std::make_shared<view::Scoreboard>(player);
  }

  static void MakeInstance() { instance_ = new Factory; }

 private:
  Factory() = default;
};

}  // namespace view

#endif  // GP_SRC_VIEW_FACTORY_H_
