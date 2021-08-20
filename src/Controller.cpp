
#include "Controller.h"
Controller::Controller() {
  CreateWindow();
}

void Controller::Display() {
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

  window->setFramerateLimit(30);
  menu = std::make_shared<view::Menu>();


  while (window->isOpen()) {
//    glClearColor(0.9, 0.6, 0.58, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if ( state == 0) {
      glClearColor(0.45, 0.5, 0.58, 1.0);
      menu->Display();

      sf::Event event;
      while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window->close();
        }
        else if (event.type == sf::Event::KeyReleased &&
              event.key.code == sf::Keyboard::P) {
          this->ChangeState(GAME);
        }
      }

    }
    else if (state == 1) {
      glClearColor(0.9, 0.6, 0.0, 1.0);
      std::shared_ptr<logic::User> u = world->GetUser();

      sf::Vector2i pos = sf::Mouse::getPosition();

      xpos = pos.x;
      ypos = pos.y;

      if (first_mouse) {
        last_x = xpos;
        last_y = ypos;
        first_mouse = false;
      }

      float xoffset = xpos - last_x;
      float yoffset = last_y - ypos; // reversed since y-coordinates go from bottom to top
      last_x = xpos;
      last_y = ypos;

      float sensitivity = 0.2f; // change this value to your liking
      xoffset *= sensitivity;
      yoffset *= sensitivity;

      yaw += xoffset;
      pitch += yoffset;

      // make sure that when pitch is out of bounds, screen doesn't get flipped
      if (pitch > 89.0f)
        pitch = 89.0f;
      if (pitch < -89.0f)
        pitch = -89.0f;

      glm::vec3 front;
      front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
      front.y = sin(glm::radians(pitch));
      front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
      camera_front = glm::normalize(front);

      camera_pos = u->GetPosition() + glm::vec3(0, 1.5, -4);
      Cam::Get()->view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);

      // controls input checken
      sf::Event event;
      while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window->close();
        }
        if (event.type == sf::Event::KeyReleased &&
            event.key.code == sf::Keyboard::D) {
          u->MoveRight(2.f);
        }
        if (event.type == sf::Event::KeyReleased &&
            event.key.code == sf::Keyboard::A) {
          u->MoveLeft(2.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          u->MoveForward(1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          u->MoveBack(1);
        }
        if (event.type == sf::Event::KeyReleased &&
            event.key.code == sf::Keyboard::Space) {
          u->Jump();
        }
        if (event.type == sf::Event::KeyReleased &&
            event.key.code == sf::Keyboard::E) {
          u->EmpCharge(world->GetPlayers());
        }
        if (event.type == sf::Event::KeyReleased &&
            event.key.code == sf::Keyboard::Escape) {
          this->ChangeState(MENU);
        }
        // camera_pos = u->GetPosition() + glm::vec3(0, 2, -3);
      }

      Clock::Get()->Update();
      world->Update();

      world->Display();

    }
    else if (state == 2) {

    }
    else {
      std::cout << "invalid game state";
    }
    window->display();
  }
}
void Controller::CreateWindow() {
  // settings for window
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 0;
  settings.majorVersion = 0;
  settings.minorVersion = 0;

  // create new window
  this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "GP",sf::Style::Default,  settings );
  this->window->setFramerateLimit(30);


  if (!gladLoadGLLoader((GLADloadproc)sf::Context::getFunction)) {
    std::cout << "no glad";
  }
  if (!gltInit())
  {
    fprintf(stderr, "Failed to initialize glText\n");
  }

  glCullFace(GL_CCW);
  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);
  glDepthFunc(GL_LEQUAL);
  glDepthRange(0.0f, 1.0f);


}
void Controller::ChangeState(gamestate newState) {
  if ( newState == 0) {
    state = MENU;
  }
  if (newState == 1) {
    state = GAME;
    world = std::make_shared<logic::World>(5);
    Cam::Reset();
  }
}
