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

    unsigned int lanechunknr= 0;

    std::shared_ptr<logic::Obstacle> MakeObstacle() override {
        return std::make_shared<logic::Obstacle>(); }

    std::shared_ptr<logic::Lane> MakeLane(glm::vec3 pos, glm::vec3 size) override {
        return std::make_shared<logic::Lane>(pos, size); }

    std::shared_ptr<logic::NPC> MakeNPC() override {
        return std::make_shared<view::NPC>(); }

    std::shared_ptr<logic::User> MakeUser(glm::vec3 pos , glm::vec3 size) override {
        return std::make_shared<view::User>(pos , size); }

    std::shared_ptr<logic::LaneChunk>
    MakeLaneChunk(glm::vec3 pos, glm::vec3 size) override {
        std::cout << "made lanechunk " << lanechunknr << std::endl;
        lanechunknr++;
        return std::make_shared<view::LaneChunk>(pos, size); }

    std::shared_ptr<logic::OCube> MakeOCube(std::shared_ptr<logic::Entity> entity) override {
        return std::make_shared<view::OCube>();
    }

    std::shared_ptr<logic::OCube> MakeOCube() override {
        return std::make_shared<view::OCube>();
    }


    static void MakeInstance() { instance_ = new EntityFactory;}

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
