//
// Created by Phili on 28/11/2020.
//

#ifndef GP_PLAYERFACTORY_HH
#define GP_PLAYERFACTORY_HH



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



#endif //GP_PLAYERFACTORY_HH