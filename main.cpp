
#include <memory>

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "view/Player.h"
#include "view/EntityFactory.h"
#include "view/World.h"

Cam* Cam::camera = 0;

logic::EntityFactory* logic::EntityFactory::instance;

int main() {

    view::EntityFactory::MakeInstance();

    sf::ContextSettings settings;
//    settings.depthBits = 24;
//    settings.stencilBits = 8;
//    settings.antialiasingLevel = 0;
//    settings.majorVersion = 0;
//    settings.minorVersion = 0;

    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Bla",sf::Style::Default,  settings );
    //window->setFramerateLimit(27);
    //window->resetGLStates();
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

    auto v = std::make_shared<view::Drawable>();


    view::World world(5);


    //logic::MainGame game(window);

    window->setFramerateLimit(27);
    //blub.setFillColor(sf::Color::Magenta);
    while (window->isOpen()) {
        glClearColor(0.3,0.5,0.0,1.0);
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }
        world.Display();

        window->display();
    }

    //game.Play();

}