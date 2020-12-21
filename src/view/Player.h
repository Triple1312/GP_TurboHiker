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

    User(glm::vec3 pos , glm::vec3 size);

    void Display() override {
        this->Update();
        this->ChangeVertices(this->GetPoints());
        this->Draw(); }

};

class NPC : public logic::NPC, public view::Drawable {
 public:
  NPC(glm::vec3 pos);

  void Display() override {
    this->Update();
    this->ChangeVertices(this->GetPoints());
    this->Draw(); }
};

}



#endif //GP_SRC_MODEL_PLAYER_H_
