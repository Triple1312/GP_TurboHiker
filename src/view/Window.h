//
// Created by phil on 7/26/21.
//

#ifndef GP_SRC_VIEW_WINDOW_H_
#define GP_SRC_VIEW_WINDOW_H_

#include <glad/glad.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "view/Player.h"
#include "view/Factory.h"

#include <thread>

#include <ft2build.h>
#include FT_FREETYPE_H

class Window {

  private:
  sf::ContextSettings settings;
  std::shared_ptr<sf::RenderWindow> window;


   bool run();

  public:

   Window();

    void close();

};

#endif  // GP_SRC_VIEW_WINDOW_H_
