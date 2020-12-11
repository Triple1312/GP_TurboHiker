#ifndef GP_PLAYER_H
#define GP_PLAYER_H

#include <iostream>
#include <deque>
#include <memory>

#include "model/Entity.h"

namespace logic{

class Player : public logic::Entity {
public:
    void Jump();

    void Roll();

    //Player(glm::vec4 ,glm::vec4 = glm::vec4(40.f/60.f, 80.f/60.f, 25.f/60.f, 0));

    void EmpCharge(std::deque<std::shared_ptr<Player>> &);

    virtual void Update();

    //void Display();

protected:
    std::uint8_t stamina;
    std::uint8_t speed; // todo: pixel per second ?
    std::uint8_t height; // if the player jumps or rolls this number will change
    std::uint8_t emp_charge;

    Player(glm::vec3 pos, glm::vec3 size) : logic::Entity(pos , size){};
    Player() = default;


};

class User : public logic::Player {
public:
    User();

    //virtual void Display(){}
};

class NPC : public logic::Player {
public:
    NPC() = default;

    virtual void Display(){}

};

}

#endif //GP_PLAYER_H
