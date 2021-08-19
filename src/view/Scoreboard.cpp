
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

  gltSetText(score_text_,temp.c_str());
  gltBeginDraw();
  gltColor(1, 1, 1, 1);
  gltDrawText2D(this->score_text_, 20, 20, 3);
  gltEndDraw();
}