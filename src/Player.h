//
// Created by Phili on 11/11/2020.
//
#ifndef GP_PLAYER_H
#define GP_PLAYER_H

#include <iostream>

#include "Entity.h"

class Player : public Entity{
public:
    void Jump();

    void Roll();

    Player(sf::Vector3f);

private:
    std::uint8_t stamina;
    std::uint8_t speed; // todo: pixel per second ?
    std::uint8_t height; // if the player jumps or rolls this number will change


};


#endif //GP_PLAYER_H
