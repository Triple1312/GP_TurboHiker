
#ifndef GP_SRC_VIEW_SCOREBOARD_H_
#define GP_SRC_VIEW_SCOREBOARD_H_

#include <glad/glad.h>

#include <iostream>
#include <string>

#define GLT_IMPLEMENTATION
#include "Utils/gltext.h"
#include "model/Scoreboard.h"

namespace view {

class Scoreboard : public logic::Scoreboard {
 public:
  explicit Scoreboard(std::shared_ptr<logic::Player>);

  ~Scoreboard() override;

  void Update() override;

  void Draw() override;

 private:
  GLTtext* score_text_ =
      gltCreateText();  // cant use smart pointers because its managed by a c
                        // lib that doesnt allow it
  GLTtext* highscore_text_ =
      gltCreateText();  // cant use smart pointers because its managed by a c
                        // lib that doesnt allow it
  GLTtext* speed_ = gltCreateText();  // cant use smart pointers because its
                                      // managed by a c lib that doesnt allow it
  GLTtext* emp_charge_text_ =
      gltCreateText();  // cant use smart pointers because its managed by a c
                        // lib that doesnt allow it

  GLTtext* empd_text =
      gltCreateText();  // cant use smart pointers because its managed by a c
                        // lib that doesnt allow it
  GLTtext* deaths_text_ =
      gltCreateText();  // cant use smart pointers because its managed by a c
                        // lib that doesnt allow it
  GLTtext* bumped_text_ =
      gltCreateText();  // cant use smart pointers because its managed by a c
                        // lib that doesnt allow it
  GLTtext* escape_text_ =
      gltCreateText();  // cant use smart pointers because its managed by a c
                        // lib that doesnt allow it
  GLTtext* time_played_text_ =
      gltCreateText();  // cant use smart pointers because its managed by a c
                        // lib that doesnt allow it
};

}  // namespace view

#endif  // GP_SRC_VIEW_SCOREBOARD_H_
