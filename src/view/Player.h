//
// Created by Phili on 03/12/2020.
//

#ifndef GP_V_PLAYER_H
#define GP_V_PLAYER_H


#include "model/Player.h"
#include "view/Drawable.hpp"


namespace view {

class User : public logic::User, public view::Drawable {
public:
    User();

    void Display() override {
        this->ChangeVertices(this->GetPoints());
        this->Draw(); }

};

class NPC : public logic::NPC, public view::Drawable {

};

}



#endif //GP_PLAYER_H
