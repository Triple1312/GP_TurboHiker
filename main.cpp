#include <memory>
#include <thread>

#include <glad/glad.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "view/Player.h"
#include "view/Factory.h"
#include "model/Clock.hpp"
#include "Utils/Random.hpp"
#include "view/Camera.hpp"



Cam* Cam::camera = nullptr;

logic::Factory* logic::Factory::instance_;

Clock* Clock::instance_;

Random Random::random_;


int main() {

//    auto window = std::make_shared<Window>();
//    std::thread t_window = window->start();

    view::Factory::MakeInstance();


    //settings voor de window (gewoon negeren)w
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 0;
    settings.minorVersion = 0;


    // aanmaken nieuw window
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "GP",sf::Style::Default,  settings );
    //window->setFramerateLimit(27);
    //window->resetGLStates();
    auto s = window->getSettings().depthBits;

    // check of glad werkt
  if (!gladLoadGLLoader((GLADloadproc)sf::Context::getFunction)) {
    std::cout << "no glad";
    return -1;
  }

  // text renderer lib checken

    glCullFace(GL_CCW);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);

    glDepthRange(0.0f, 1.0f);
//    auto v = std::make_shared<view::Drawable>();


    logic::World world(5);

    std::shared_ptr<logic::User> u = world.GetUser();

    auto sb = world.GetScoreBoard();

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
    window->popGLStates();

    //window->resetGLStates();
    //Clock::Get()->Reset();
    //blub.setFillColor(sf::Color::Magenta);

//    Text text("recources/Fonts/Diane_de_France/Diane_de_France.ttf", 20, 20, 400);
    glm::mat4 ortogonal = glm::ortho(0.0f, 800.f, 0.0f, 600.f);
//    text.SetString("24");
//    auto tr = std::make_unique<afgl::TextRenderer>("recources/Fonts/Diane_de_France/Diane_de_France.ttf", glm::value_ptr(ortogonal));

  sf::CircleShape shape(200.f);
  shape.setFillColor(sf::Color::Magenta);

  glClearDepth(1.f);
// Enable Z-buffer read and write
  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);


    while (window->isOpen() ) {


        glClearColor(0.9, 0.6, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


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
              u->EmpCharge(world.GetPlayers());
            }
            // camera_pos = u->GetPosition() + glm::vec3(0, 2, -3);
          }

        Clock::Get()->Update();
        world.Update();


        world.Display();

      //sb->Draw(&window); //todo is momenteel gwn logic
//        tr->draw("djsahkdja", 200.f, 200.f, 1.0);

        window->display();
    }

    //game.Play();

}