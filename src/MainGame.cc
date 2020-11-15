
#include "MainGame.h"

void MainGame::DrawField() {
   this->draw->DrawLanes(const_cast<std::deque<std::shared_ptr<Lane>> &>(this->field->GetLanes()));
   this->draw->DrawEntities((std::deque<std::shared_ptr<Entity>> &) this->field->GetPlayers());
}

MainGame::MainGame(sf::RenderWindow& i_window) : window(i_window){
    REQUIRE(&i_window != nullptr, "Window doesnt exist");
    this->draw = std::make_unique<Draw>(i_window);
    this->field = std::make_unique<Field>(ppp::Vec3F(10,10,10), 5);
    ENSURE(this != nullptr, "Construction of Maingame failed");
//    this->window = i_window;
}

//MainGame::MainGame() {
//    this->field = std::make_unique<Field>(ppp::Vec3F(600,600,600), 5);
//}

void MainGame::Play() {
    window.setFramerateLimit(27);
    //sf::RectangleShape blub(sf::Vector2f(200, 200));
    //blub.setPosition(200 ,200 );
    //blub.setFillColor(sf::Color::Magenta);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (sf::Event::KeyReleased == event.type && event.key.code == sf::Keyboard::A ) {
                field->MovePlayer(-1);
            }
            else if ( sf::Event::KeyReleased == event.type && event.key.code == sf::Keyboard::D ) {
                field->MovePlayer(1);
            }
//            else if ( sf::Event::KeyReleased == event.type && event.key.code == sf::Keyboard::E ) {
//                field->MovePlayer(1);
//            }
        }
        //window.draw(blub);
        DrawField();
        window.display();
    }
}
