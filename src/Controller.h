//
// Created by phil on 7/26/21.
//

#ifndef GP_SRC_CONTROLLER_H_
#define GP_SRC_CONTROLLER_H_

#include <thread>
#include <iostream>

#include <glad/glad.h>
#include <SFML/Graphics.hpp>

#define GLT_IMPLEMENTATION
#include "Utils/gltext.h"

#include "model/World.h"
#include "view/Factory.h"
#include "model/Clock.hpp"
#include "Utils/Random.hpp"
#include "view/Menu.h"



enum gamestate {MENU = 0, GAME = 1, END = 2};

class Controller {
  std::shared_ptr<logic::World> world;
  std::shared_ptr<sf::Window> window;
  std::shared_ptr<view::Menu> menu;


  gamestate state = MENU;

  void ChangeState(gamestate);

 public:

  Controller();

  void Display();

  void CreateWindow();


};


#endif  // GP_SRC_CONTROLLER_H_
