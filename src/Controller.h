//
// Created by phil on 7/26/21.
//

#ifndef GP_SRC_CONTROLLER_H_
#define GP_SRC_CONTROLLER_H_

#include <thread>
#include <iostream>

#include "view/Window.h"
#include "model/Model.h"

class Controller {
  std::unique_ptr<Model> model;
  std::unique_ptr<Window> view;

 public:
  Controller();

  void start();

};

#endif  // GP_SRC_CONTROLLER_H_
