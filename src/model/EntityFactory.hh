#ifndef GP_SRC_MODEL_ENTITYFACTORY_HH_
#define GP_SRC_MODEL_ENTITYFACTORY_HH_

#include "model/Obstacle.h"
#include "model/Lane.h"
#include "model/Player.h"
#include "model/World.h"

namespace logic {

class EntityFactory {

 public:

  EntityFactory(EntityFactory &) = delete;

  virtual ~EntityFactory() { delete instance_; }

  static logic::EntityFactory *Get() {
//            if (!instance_) {
//                instance_  = new EntityFactory;
//            }
    return instance_;
  }

  virtual std::shared_ptr<logic::NPC> MakeNPC(glm::vec3 pos) { return std::make_shared<logic::NPC>(pos); }

  virtual std::shared_ptr<logic::User> MakeUser() { return std::make_shared<logic::User>(); }

  virtual std::shared_ptr<logic::User> MakeUser(glm::vec3 pos, glm::vec3 size) {}

  virtual std::shared_ptr<logic::Obstacle> MakeObstacle() { return std::make_shared<logic::Obstacle>(); }

  virtual std::shared_ptr<logic::Lane> MakeLane(glm::vec3 pos, glm::vec3 size) { LaneChunk(pos, size); }

  virtual std::shared_ptr<logic::LaneChunk> MakeLaneChunk(glm::vec3 pos,
                                                          glm::vec3 size) { return std::make_shared<logic::LaneChunk>(); }

  virtual std::shared_ptr<logic::OCube> MakeOCube(std::shared_ptr<logic::Entity> entity) {}

  virtual std::shared_ptr<logic::OCube> MakeOCube() {
    return std::make_shared<logic::OCube>();
  }

 protected:

  static logic::EntityFactory *instance_;

  EntityFactory() = default;

};

//model::Entity EntityFactory::MakeEntity(const EntityType &type) {
//
//}

//logic::User EntityFactory::MakeUser() {
//    return PFac.MakeUser();
//}

//logic::Obstacle EntityFactory::MakeObstacle() {
//    return logic::Obstacle();
//}

//std::shared_ptr<logic::NPC> EntityFactory::MakeNPC() {
//    //return PFac.MakeNPC();
//}

} // model

#endif //GP_SRC_MODEL_ENTITYFACTORY_HH_
