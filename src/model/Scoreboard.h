//
// Created by Phili on 11/11/2020.
//

#ifndef GP_SCOREBOARD_H
#define GP_SCOREBOARD_H

#include <iostream>

#include "Widget.h"

namespace logic {

class Scoreboard : public Widget {
 private:
  std::uint32_t score_{};

  Scoreboard() = default;

 public:
  static Scoreboard &GetInstance() {
    static Scoreboard instance;
    return instance;
  }
};

}

#endif //GP_SCOREBOARD_H
