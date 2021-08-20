
#include "Menu.h"

view::Menu::Menu() {
  gltInit();
  gltSetText(play_, "Play");
  gltSetText(press_play_, "press P to play");
  gltSetText(name, "TURBOHIKER by Philippe Voet");
}
void view::Menu::Display() {
  gltBeginDraw();
  gltColor(1, 1, 1, 1);
  gltDrawText2D(this->play_, 100, 180, 7);
  gltDrawText2D(this->press_play_, 100, 300, 2);
  gltDrawText2D(this->name, 120, 30, 2.3);
  gltEndDraw();
}
view::Menu::~Menu() {
  gltDeleteText(this->play_);
  gltDeleteText(this->press_play_);
  gltDeleteText(this->highscore_);
  gltDeleteText(this->name);
}
