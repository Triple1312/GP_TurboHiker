#ifndef GP_ENTITYFACTORY_HH
#define GP_ENTITYFACTORY_HH

#include "model/Obstacle.h"
#include "model/Lane.h"
#include "model/Player.h"
#include "model/World.h"

namespace logic {

    class EntityFactory {

    public:

        EntityFactory(EntityFactory&) = delete;

        ~EntityFactory(){ delete instance;}

        static logic::EntityFactory* Get() {
//            if (!instance) {
//                instance  = new EntityFactory;
//            }
            return instance;
        }

        virtual std::shared_ptr<logic::NPC> MakeNPC() {  }

        virtual std::shared_ptr<logic::User> MakeUser() {  }

        virtual std::shared_ptr<logic::Obstacle> MakeObstacle() {  }

        virtual std::shared_ptr<logic::Lane> MakeLane(glm::vec3 pos, glm::vec3 size) {  return nullptr;}

        virtual std::shared_ptr<logic::LaneChunk> MakeLaneChunk(glm::vec3 pos, glm::vec3 size) {  }

    protected:

        static logic::EntityFactory* instance ;

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

#endif //GP_ENTITYFACTORY_HH
