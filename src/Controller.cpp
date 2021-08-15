//
// Created by phil on 7/26/21.
//

#include "Controller.h"
Controller::Controller() {
  model = std::make_unique<Model>();
  view = std::make_unique<Window>();


}

void startWindow() {

}

void startWorld() {

}

void Controller::start() {
    std::thread t_window (startWindow);
    std::thread t_model (startWorld);

    t_window.join();
    t_model.detach();

}
