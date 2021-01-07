#ifndef GP_SRC_VIEW_FACTORY_H_
#define GP_SRC_VIEW_FACTORY_H_

#include <memory>

#include "model/Factory.h"

#include "view/Player.h"
#include "view/Obstacle.h"
#include "view/Lane.h"
#include "view/Scoreboard.h"

namespace view {

class Factory : public logic::Factory {
public:

    unsigned int lanechunknr_= 0;

    std::shared_ptr<logic::Obstacle> MakeObstacle(glm::vec3 pos, logic::ObstType obst_type) override {
      if (obst_type == logic::WALL ) {
        return std::make_shared<view::OCube>(pos);
      }
      else if ( obst_type == logic::HORDE) {
        return std::make_shared<view::Horde>(pos);
      }
      else if ( obst_type == logic::STEP_1 ) {
        return std::make_shared<view::Ramp1>(pos);
      }
      else if ( obst_type == logic::STEP_2 ) {
        return std::make_shared<view::Ramp2>(pos);
      }

    }

    std::shared_ptr<logic::Lane> MakeLane(glm::vec3 pos, glm::vec3 size) override {
        return std::make_shared<Lane>(pos, size); }

    std::shared_ptr<logic::NPC> MakeNPC(glm::vec3 pos) override {
        return std::make_shared<NPC>(pos); }

    std::shared_ptr<logic::User> MakeUser(glm::vec3 pos , glm::vec3 size) override {
        return std::make_shared<User>(pos , size); }


    std::shared_ptr<logic::OCube> MakeOCube(std::shared_ptr<logic::Entity> entity) override {
        return std::make_shared<OCube>(entity->GetPosition());
    }

    std::shared_ptr<logic::OCube> MakeOCube() override {
        return std::make_shared<OCube>(glm::vec3(0.f));
    }

  std::shared_ptr<logic::Scoreboard> MakeScoreBoard(std::shared_ptr<logic::Player> player) override {
      return std::make_shared<view::Scoreboard>(player);
    }


    static void MakeInstance() { instance_ = new Factory;}

private:

    Factory() = default;

};


//std::shared_ptr<logic::Obstacle> Factory::MakeObstacle() {
//
//}
//
//std::shared_ptr<logic::NPC> Factory::MakeNPC() {
//    return std::make_shared<view::NPC>();
//}
//
//std::shared_ptr<logic::LaneChunk> Factory::MakeLaneChunk(glm::vec3 pos, glm::vec3 size) {
//    return std::make_shared<view::LaneChunk>( pos, size);
//}
//
//std::shared_ptr<logic::User> Factory::MakeUser() {
//
//}
//
//std::shared_ptr<logic::Lane> Factory::MakeLane(glm::vec3 pos, glm::vec3 size) {
//    ;
//}
//
//} // namespace view

}


#endif //GP_SRC_VIEW_FACTORY_H_
