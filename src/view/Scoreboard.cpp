//
// Created by ppp on 1/3/21.
//

#include "Scoreboard.h"

#include <utility>
void view::Scoreboard::Update() {
  logic::Scoreboard::Update();
  string_ = std::to_string(this->GetScore());
}

view::Scoreboard::Scoreboard(std::shared_ptr<logic::Player> entity) : logic::Scoreboard( std::move(entity) ) {
  this->font_ = sf::Font();
  font_.loadFromFile("recources/Fonts/Diane de France/Diane_de_France.ttf");
  this->string_ = "0";
  this->text_ = sf::Text(this->string_, this->font_);
  this->text_.setString(string_);
  this->text_.setPosition( 200, 200);
  this->text_.setCharacterSize(50);
  this->text_.setFillColor(sf::Color::White);

}
void view::Scoreboard::Draw(void * window) {
  auto win = reinterpret_cast<sf::RenderWindow*>(window);
  //win->pushGLStates();
  win->draw(this->text_);
  //win->popGLStates();

}