#include <memory>

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "view/Player.h"
#include "view/EntityFactory.h"
#include "view/World.h"
#include "model/Clock.hpp"

Cam* Cam::camera = 0;

logic::EntityFactory* logic::EntityFactory::instance;

Clock* Clock::instance;

int main() {

    view::EntityFactory::MakeInstance();

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 0;
    settings.minorVersion = 0;

    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Bla",sf::Style::Default,  settings );
    //window->setFramerateLimit(27);
    window->resetGLStates();
    auto s = window->getSettings().depthBits;

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }

    glCullFace(GL_CCW);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);

    glDepthRange(0.0f, 1.0f);

    auto v = std::make_shared<view::Drawable>();


    view::World world(5);

    std::shared_ptr<logic::User> u = world.GetUser();

    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);

    const float cameraSpeed = 0.1f;

    bool firstMouse = true;
    float yaw   = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
    float pitch =  0.0f;
    float lastX =  800.0f / 2.0;
    float lastY =  600.0 / 2.0;
    float fov   =  45.0f;

    float xpos = 800.f/2;
    float ypos = 600.f/2;


    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);

    window->setFramerateLimit(60);
    //blub.setFillColor(sf::Color::Magenta);
    while (window->isOpen()) {
        glClearColor(0.9,0.6,0.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        sf::Vector2i pos = sf::Mouse::getPosition();

        xpos = pos.x;
        ypos = pos.y;

        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
        lastX = xpos;
        lastY = ypos;

        float sensitivity = 0.3f; // change this value to your liking
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
        cameraFront = glm::normalize(front);

        cameraPos = u->GetPosition() + glm::vec3(0, 1.5, -4);
        Cam::Get()->view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D) {
                u->MoveRight(2.f);
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) {
                u->MoveLeft(2.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                u->MoveForward(1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                u->MoveBack(1);
            }
            //cameraPos = u->GetPosition() + glm::vec3(0, 2, -3);

        }

        Clock::Get()->Update();
        world.Display();


        window->display();
    }

    //game.Play();

}