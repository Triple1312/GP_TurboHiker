//
// Created by Phili on 28/11/2020.
//

#ifndef GP_SRC_MODEL_PLAYERFACTORY_HH_
#define GP_SRC_MODEL_PLAYERFACTORY_HH_

namespace logic {

class NPC;
class User;

class PlayerFactory {

 public:

  PlayerFactory() = default;

  //Player MakePlayer();

  User MakeUser();

  NPC MakeNPC();

};

logic::User PlayerFactory::MakeUser() {
  return User();
}

logic::NPC PlayerFactory::MakeNPC() {
  //return model::NPC();
}

} // factory



#endif //GP_SRC_MODEL_PLAYERFACTORY_HH_