//
// Created by Phili on 11/11/2020.
//

#include "Scoreboard.h"

#include <utility>

logic::Scoreboard::Scoreboard(std::shared_ptr<logic::Player> entity) {
  std::fstream gameinfo;
  gameinfo.open("gamedata.json");
  gamefile << gameinfo;
  highscore_ = gamefile.at("highscore");

  this->entity_ = std::move(entity);
}
const uint32_t &logic::Scoreboard::GetScore() const { return this->score_; }
void logic::Scoreboard::Update() {
//  score_ += (float)this->entity_->velocity_.z / GameSettings::PlayerSpeed() *
//            (float)Clock::Get()->GetTimeSinceLastInMilliSeconds();
  score_ = this->entity_->score_;
}
void logic::Scoreboard::Finish() {
  if(GetScore() > highscore_) {
    gamefile["highscore"] = int(GetScore());
    std::fstream o("gamedata.json");
    o << gamefile;
  }
}

