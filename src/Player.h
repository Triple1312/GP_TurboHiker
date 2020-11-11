//
// Created by Phili on 11/11/2020.
//
#include <iostream>

#include "Entity.h"


#ifndef GP_PLAYER_H
#define GP_PLAYER_H


class Player : public Entity{
public:
    void Jump();

    void Roll();

private:
    std::uint8_t stamina;
    std::uint8_t speed; // todo: pixel per second ?
    std::uint8_t height; // if the player jumps or rolls this number will change


};


#endif //GP_PLAYER_H
