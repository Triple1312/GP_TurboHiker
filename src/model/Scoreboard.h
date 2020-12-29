
#ifndef GP_SRC_MODEL_SCOREBOARD_H_
#define GP_SRC_MODEL_SCOREBOARD_H_

#include <iostream>



namespace logic {

class Scoreboard {
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

#endif //GP_SRC_MODEL_SCOREBOARD_H_
