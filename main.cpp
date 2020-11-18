
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "src/MainGame.h"

int main() {
    //std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "GP");
    //std::cout << glGetString(GL_VERSION) << std::endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "GP");
    MainGame game(window);

    game.Play();

}