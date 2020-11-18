//
// Created by Phili on 12/11/2020.
//

#include "Draw.h"

void Draw::DrawEntities(std::deque<std::shared_ptr<Entity>>& entities) {
    auto  texture = std::make_shared<sf::Texture>();
    texture->loadFromFile("recources/Textures/Chell/Chell_back_still.png");
    double scaler =  window.getSize().x / 10;

    for ( auto e : entities) {
        //auto rot_x = glm::rotate(glm::mat4(), glm::radians(this->angle), glm::vec3(1, 0, 0));
        auto view = glm::lookAt(glm::vec3(5, 3, 0), glm::vec3(5, 0, 10), glm::vec3(0, 1, 0));
        auto proj = glm::perspective(glm::radians(45.f), 800.f/600.f, 0.1f, 0.2f);
        //auto point_on_screen = proj * view * glm::vec4(e->pos.x, e->pos.y, e->pos.z, 1 );
        //auto size_on_screen = proj * view * glm::vec4(e->size.x, e->size.y, e->size.z, 0 );
        std::deque<glm::vec4> ps = e->GetFace(1);

        sf::ConvexShape sh(4);
        glm::vec4 p0 = proj * view * ps[0];
        sh.setPoint(0, sf::Vector2f(p0.x * scale, p0.y * scale));
        glm::vec4 p1 = proj * view * ps[1];
        sh.setPoint(1, sf::Vector2f(p1.x * scale, p1.y * scale));
        glm::vec4 p2 = proj * view * ps[2];
        sh.setPoint(2, sf::Vector2f(p2.x * scale, p2.y * scale));
        glm::vec4 p3 = proj * view * ps[3];
        sh.setPoint(3, sf::Vector2f(p3.x * scale, p3.y * scale));




        //sf::RectangleShape rect(sf::Vector2f(e->size.x * scaler, e->size.z * scaler));
        //rect.setPosition(e->pos.x * scaler, e->pos.z * scaler);
        //rect.setFillColor(sf::Color::Blue);
        sh.setTexture(texture.get());
        //sh.setFillColor(sf::Color::Blue);
        //window.draw(sh);
    }
}

void Draw::DrawLanes(std::deque<std::shared_ptr<Lane>>& lanes) {
    auto  texture = std::make_shared<sf::Texture>();
    texture->loadFromFile("recources/Textures/portal_2_textures/metal/metalwall048e.jpg");
    double scaler =  window.getSize().x /10;


    for ( auto l : lanes ) {
        auto a = *l;
        for ( auto c : l->GetLaneChunks() ) {

            float omhoog = 90.f;
            float zijwaarts = 0.0f;

            //glm::vec3 front = glm::vec3 (0.0f, 0.0f, -1.0f);
            glm::vec3 camera_pos = glm::vec3 (-5.0f, 1.0f, 0.0f);
            glm::vec3 camera_up = glm::vec3 (0.0f, 1.0f, 0.0f);
            //glm::vec3 cameraT = glm::vec3(0.0f, 0.0f, 0.0f);;
            //glm::vec3 cameraD = glm::normalize(camera_pos - cameraT);
            //glm::vec3 cameraR = glm::normalize(glm::cross(camera_up, cameraD));

            auto dir_y = glm::sin(glm::radians(30.f));
            glm::vec3 dir_f;
            dir_f.y = dir_y;
            dir_f.z = -1;
            dir_f = glm::normalize(dir_f);


            glm::mat4 view = glm::lookAt(camera_pos, camera_pos + dir_f, camera_up);
            auto proj = glm::perspective(glm::radians(90.f), 800.f/600.f, 0.1f, 100.0f);

            //sf::RectangleShape rect(sf::Vector2f(c->size.x * scaler, c->size.z * scaler));
            //rect.setPosition(c->pos.x * scaler, c->pos.z * scaler);

            //rect.setTexture(texture.get());

            std::deque<glm::vec4> ps = c->GetFace(0);
            for ( auto& p : ps ) {
                std::cout << p.x << " " << p.y << " " << p.z << " " << p.w << std::endl;

            }

            sf::ConvexShape sh(4);
            glm::vec4 p0 =  proj * view * ps[0];
            sh.setPoint(0, sf::Vector2f(p0.x * scale, p0.y * scale));
            glm::vec4 p1 =  proj * view  * ps[1];
            sh.setPoint(1, sf::Vector2f(p1.x * scale, p1.y * scale));
            glm::vec4 p2 =  proj * view  * ps[2];
            sh.setPoint(2, sf::Vector2f(p2.x* scale, p2.y * scale));
            glm::vec4 p3 =  proj * view  * ps[3];
            sh.setPoint(3, sf::Vector2f(p3.x* scale, p3.y* scale));
//            std::cout << p0.x << " " << p0.y << " " << p0.z << " " << p0.w << std::endl;
//            std::cout << p1.x << " " << p1.y << " " << p1.z << " " << p1.w << std::endl;
//            std::cout << p2.x << " " << p2.y << " " << p2.z << " " << p2.w << std::endl;
//            std::cout << p3.x << " " << p3.y << " " << p3.z << " " << p3.w << std::endl;

            sh.setFillColor(sf::Color::Red);
            sh.setOutlineThickness(2);
            sh.setOutlineColor(sf::Color::White);
            if (c == *(l->GetLaneChunks().end() -1)  ) {
                sh.setFillColor(sf::Color::Blue);
            }
            else if ( c == *l->GetLaneChunks().begin()) {
                sh.setFillColor(sf::Color::Green);
            }

            window.draw(sh);
        }
    }
}

Draw::Draw(sf::RenderWindow &window) : window(window){

}

std::shared_ptr<sf::RectangleShape> Draw::CalcFace(glm::vec4 p, glm::vec4 s, std::uint8_t face_nr) {
    if ( face_nr == 0 ) {
        auto shape = std::make_shared<sf::RectangleShape>(sf::Vector2f (s.x, s.z));
        
    }
}

glm::mat4 Draw::GetRotateX(double angle) {
    return glm::mat3(0, 0, 0,
                     0, std::cos(angle), -std::sin(angle),
                     0, std::sin(angle), std::cos(angle));
}

