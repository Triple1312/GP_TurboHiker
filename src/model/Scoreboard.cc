

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
  speed = this->entity_->velocity_.z;
  emp_charge_ = this->entity_->emp_charge_;
}
void logic::Scoreboard::Finish() {
  this->finished = true;
  if(GetScore() > highscore_) {
    gamefile["highscore"] = int(GetScore());
    std::fstream o("gamedata.json");
    o.clear();
    o << gamefile;
  }
}
const uint32_t& logic::Scoreboard::GetHighScore() const {
  return this->highscore_;
}
const float& logic::Scoreboard::GetSpeed() const { return this->speed; }
const float& logic::Scoreboard::GetEMP() const { return this->emp_charge_; }
const bool& logic::Scoreboard::GetFinished() const { return this->finished; }
const std::shared_ptr<logic::Player>& logic::Scoreboard::GetUser() const { return this->entity_; }
