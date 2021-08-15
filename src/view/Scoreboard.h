//
// Created by ppp on 1/3/21.
//

#ifndef GP_SRC_VIEW_SCOREBOARD_H_
#define GP_SRC_VIEW_SCOREBOARD_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "model/Scoreboard.h"

namespace view {

class Scoreboard : public logic::Scoreboard {
 public:
  explicit Scoreboard(std::shared_ptr<logic::Player>);

  void Update() override;

  void Draw(void*) override;

 private:
  sf::Text text_;

  sf::Font font_;

  sf::String string_;
};

}  // namespace view

#endif  // GP_SRC_VIEW_SCOREBOARD_H_
