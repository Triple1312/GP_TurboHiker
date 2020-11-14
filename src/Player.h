//
// Created by Phili on 11/11/2020.
//
#ifndef GP_PLAYER_H
#define GP_PLAYER_H

#include <iostream>
#include <deque>
#include <memory>

#include "Entity.h"

class Player : public Entity{
public:
    void Jump();

    void Roll();

    Player(sf::Vector3f);

    void SetPosition(sf::Vector3f);

    void EmpCharge(std::deque<std::shared_ptr<Player>>&);

protected:
    std::uint8_t stamina;
    std::uint8_t speed; // todo: pixel per second ?
    std::uint8_t height; // if the player jumps or rolls this number will change
    std::uint8_t emp_charge;

};

class User : public Player {

};

class NPC : public Player {
    std::uint8_t npc_type;
};


#endif //GP_PLAYER_H
