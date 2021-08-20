
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
  std::string temp4 = "emp: " + std::to_string(this->GetEMP());
  gltSetText(score_text_,temp.c_str());
  gltSetText(highscore_text_,temp2.c_str());

  if(this->GetFinished()) {
    std::string temp5 = "bumps: " + std::to_string(this->GetUser()->bumped_);
    std::string temp6 = "deaths: " + std::to_string(this->GetUser()->deaths);
    std::string temp7 = "EMP's used: " + std::to_string(this->GetUser()->empd_);
    std::string temp8 = "press ESC to continue";
    std::string temp9 = "time played: " + std::to_string(Clock::Get()->GetTimeAsSeconds()) + " seconds";
    gltSetText(bumped_text_, temp5.c_str());
    gltSetText(deaths_text_, temp6.c_str());
    gltSetText(empd_text, temp7.c_str());
    gltSetText(escape_text_, temp8.c_str());
    gltSetText(time_played_text_, temp9.c_str());
    glClearColor(0.72, 0.63, 0.36, 1.0);
    gltBeginDraw();
    gltColor(1, 1, 1, 1);
    if(this->GetUser()->dead) {
      gltColor(1, 0, 0, 1);
    }
    gltDrawText2D(this->score_text_, 50, 100, 2);
    gltDrawText2D(this->highscore_text_, 50, 200, 2);
    gltDrawText2D(this->time_played_text_, 50, 300, 2);

    gltDrawText2D(this->deaths_text_, 500, 100, 2);
    gltDrawText2D(this->empd_text, 500, 200, 2);
    gltDrawText2D(this->bumped_text_, 500, 300, 2);

    gltDrawText2D(escape_text_, 50, 440, 3.5);
    gltEndDraw();
    return;
  }


  gltSetText(speed_,temp3.c_str());
  gltSetText(emp_charge_text_,temp4.c_str());
  gltBeginDraw();
  gltColor(1, 1, 1, 1);
  gltDrawText2D(this->score_text_, 15, 40, 1.7);
  gltDrawText2D(this->highscore_text_, 15, 10, 1.7);
  gltDrawText2D(this->speed_, 400, 10, 1.7);
  if (this->GetEMP() >= 1) {
    gltColor(0.4, 0.4, 1, 1);
  }
  gltDrawText2D(this->emp_charge_text_, 400, 40, 1.7);
  gltEndDraw();
}
view::Scoreboard::~Scoreboard() {
  gltDeleteText(this->speed_);
  gltDeleteText(this->highscore_text_);
  gltDeleteText(this->score_text_);
  gltDeleteText(this->emp_charge_text_);
}
