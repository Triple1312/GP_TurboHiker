//
// Created by phil on 7/26/21.
//

#include "Window.h"
void Window::close() { return ; }


bool Window::run() {


//  window->setFramerateLimit(27);
//  window->resetGLStates();
  auto s = window->getSettings().depthBits;


  // text renderer lib checken
  FT_Library ft;
  if (FT_Init_FreeType(&ft))
  {
    std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
    throw std::runtime_error("ERROR::FREETYPE: Could not init FreeType Library");
  }


  glm::vec3 camera_pos   = glm::vec3(0.0f, 0.0f, 3.0f);
  glm::vec3 camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
  glm::vec3 camera_up    = glm::vec3(0.0f, 1.0f, 0.0f);

  const float kCameraSpeed = 0.1f;

  bool first_mouse = true;
  float yaw   = 90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
  float pitch =  0.0f;
  float last_x =  800.0f / 2.0;
  float last_y =  600.0 / 2.0;
  float fov   =  45.0f;

  float xpos = 800.f/2;
  float ypos = 600.f/2;


  glm::vec3 front;
  front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  front.y = sin(glm::radians(pitch));
  front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  camera_front = glm::normalize(front);

  window->setFramerateLimit(144);
  window->popGLStates();

  while (window->isOpen()) {
    glCullFace(GL_CCW);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);

    glDepthRange(0.0f, 1.0f);
    glClearColor(0.9, 0.6, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  }

}

Window::Window() {
  if (!gladLoadGLLoader((GLADloadproc)sf::Context::getFunction)) {
    std::cout << "no glad";
//    throw std::runtime_error("Was\'nt able to initialize glad");
  }

  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 0;
  settings.majorVersion = 0;
  settings.minorVersion = 0;

  // aanmaken nieuw window
  this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Bla",sf::Style::Default,  settings );

  glCullFace(GL_CCW);

  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);
  glDepthFunc(GL_LEQUAL);

  glDepthRange(0.0f, 1.0f);
  window->pushGLStates();

}
