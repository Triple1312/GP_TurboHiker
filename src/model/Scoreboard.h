
#ifndef GP_SRC_MODEL_SCOREBOARD_H_
#define GP_SRC_MODEL_SCOREBOARD_H_

#include <iostream>
#include <memory>
#include <fstream>

#include <Utils/json.hpp>

#include "model/Player.h"

namespace logic {

class Scoreboard {
 public:
  explicit Scoreboard(std::shared_ptr<logic::Player>);

  virtual ~Scoreboard() = default;

  const uint32_t &GetScore() const;
  const uint32_t &GetHighScore() const;
  const float &GetSpeed() const;
  const float &GetEMP() const;
  const bool &GetFinished() const;



  virtual void Update();

  // the void* is used to pass the window class of the given engine
  virtual void Draw() { Update();}

  virtual void Finish();

 protected:
  const std::shared_ptr<logic::Player> &GetUser() const;

 private:
  std::shared_ptr<logic::Player> entity_;

  nlohmann::json gamefile;

  std::uint32_t score_ = 0;

  std::uint32_t highscore_ = 0;

  float emp_charge_;

  float speed = 0;

  bool finished = false;
};

}  // namespace logic

#endif  // GP_SRC_MODEL_SCOREBOARD_H_
