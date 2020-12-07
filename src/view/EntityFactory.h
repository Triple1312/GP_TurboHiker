#ifndef GP_ENTITYFACTORY_H
#define GP_ENTITYFACTORY_H

#include <memory>

#include "model/EntityFactory.hh"

#include "view/Player.h"
#include "view/Obstacle.h"
#include "view/Lane.h"

namespace view {

class EntityFactory : public logic::EntityFactory {
public:

    std::shared_ptr<logic::Obstacle> MakeObstacle() override {
        return std::make_shared<view::Obstacle>(); }

    std::shared_ptr<logic::Lane> MakeLane(glm::vec3 pos, glm::vec3 size) override {
        return std::make_shared<logic::Lane>(pos, size); }

    std::shared_ptr<logic::NPC> MakeNPC() override {
        return std::make_shared<view::NPC>(); }

    std::shared_ptr<logic::User> MakeUser() override {
        return std::make_shared<view::User>(); }

    std::shared_ptr<logic::LaneChunk>
    MakeLaneChunk(glm::vec3 pos, glm::vec3 size) override {
        return std::make_shared<view::LaneChunk>(pos, size); }


    static void MakeInstance() { instance = new EntityFactory;}

private:

    EntityFactory() = default;

};


//std::shared_ptr<logic::Obstacle> EntityFactory::MakeObstacle() {
//
//}
//
//std::shared_ptr<logic::NPC> EntityFactory::MakeNPC() {
//    return std::make_shared<view::NPC>();
//}
//
//std::shared_ptr<logic::LaneChunk> EntityFactory::MakeLaneChunk(glm::vec3 pos, glm::vec3 size) {
//    return std::make_shared<view::LaneChunk>( pos, size);
//}
//
//std::shared_ptr<logic::User> EntityFactory::MakeUser() {
//
//}
//
//std::shared_ptr<logic::Lane> EntityFactory::MakeLane(glm::vec3 pos, glm::vec3 size) {
//    ;
//}
//
//} // namespace view

}


#endif //GP_ENTITYFACTORY_H
