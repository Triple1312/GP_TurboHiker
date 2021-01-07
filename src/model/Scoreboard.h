
#ifndef GP_SRC_MODEL_SCOREBOARD_H_
#define GP_SRC_MODEL_SCOREBOARD_H_

#include <iostream>
#include <memory>
#include "model/Player.h"


namespace logic {

class Scoreboard {
 public:
  explicit Scoreboard(std::shared_ptr<logic::Player>);

  const uint32_t &GetScore() const;

  virtual void Update();

  // the void* is used to pass the window class of the given engine
  virtual void Draw(void*){

  }

 private:

  std::shared_ptr<logic::Player> entity_;

  std::uint32_t score_ = 0;

};

}

#endif //GP_SRC_MODEL_SCOREBOARD_H_
