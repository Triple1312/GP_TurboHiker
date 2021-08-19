
#include "Scoreboard.h"

#include <utility>
void view::Scoreboard::Update() {
  logic::Scoreboard::Update();

}

view::Scoreboard::Scoreboard(std::shared_ptr<logic::Player> entity)
    : logic::Scoreboard(std::move(entity)) {
  if (!gltInit())
  {
    fprintf(stderr, "Failed to initialize glText\n");
  }
}
void view::Scoreboard::Draw() {
  Update();
  std::string temp = "score: " + std::to_string(this->GetScore());
  std::string temp2 = "highscore: " + std::to_string(this->GetHighScore());
  std::string temp3 = "speed: " + std::to_string(this->GetSpeed());

  gltSetText(score_text_,temp.c_str());
  gltSetText(highscore_text_,temp2.c_str());
  gltSetText(speed_,temp3.c_str());
  gltBeginDraw();
  gltColor(1, 1, 1, 1);
  gltDrawText2D(this->score_text_, 15, 40, 1.7);
  gltDrawText2D(this->highscore_text_, 15, 10, 1.7);
  gltDrawText2D(this->speed_, 400, 10, 1.7);
  gltEndDraw();
}
view::Scoreboard::~Scoreboard() {
  gltDeleteText(this->speed_);
  gltDeleteText(this->highscore_text_);
  gltDeleteText(this->score_text_);
}
