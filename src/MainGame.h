/*
 * This is the controller of the entire project
 */

#ifndef GP_MAINGAME_H
#define GP_MAINGAME_H

#include <memory>
#include <deque>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "Field.h"
#include "Scoreboard.h"
#include "Menu.h"
#include "View/Draw.h"


class MainGame {
    std::unique_ptr<Field> field;
    std::unique_ptr<Scoreboard> board;
    std::unique_ptr<Draw> draw;

    sf::RenderWindow& window;

    glm::vec4 space = glm::vec4(10, 10, 10, 0);

    void DrawField();

public:
    MainGame(sf::RenderWindow& i_window);

    MainGame();

    void Play();


};


#endif //GP_MAINGAME_H
