#ifndef GP_SRC_VIEW_PLAYER_H_
#define GP_SRC_VIEW_PLAYER_H_

#include "model/Player.h"
#include "view/Drawable.hpp"

namespace view {

class User : public logic::User, public view::Drawable {
 public:
  User();

  ~User() override = default;

  User(glm::vec3 pos, glm::vec3 size);

  void Display() override {
    this->Update();
    this->ChangeVertices(this->GetPoints());
    this->Draw();
  }
};

class NPC : public logic::NPC, public view::Drawable {
 public:
  explicit NPC(glm::vec3 pos);

  void Display() override {
    this->Update();
    this->ChangeVertices(this->GetPoints());
    this->Draw();
  }
};

class KillerNPC : public logic::KillerNPC, public view::Drawable {
  public:
   ~KillerNPC() override = default;
   explicit KillerNPC(glm::vec3 pos);

   void Display() override {
     this->Update();
     this->ChangeVertices(this->GetPoints());
     this->Draw();
   }
};

}  // namespace view

#endif  // GP_SRC_MODEL_PLAYER_H_
