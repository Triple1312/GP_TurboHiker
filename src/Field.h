//
// Created by Phili on 11/11/2020.
//

#ifndef GP_FIELD_H
#define GP_FIELD_H

#include <memory>
#include <vector>
#include <deque>
#include <iostream>

#include "Widget.h"
#include "Lane.h"
#include "Entity.h"
#include "Player.h"
#include "DisignByContract.h"


class Field : public Widget{
public:
    const std::deque<std::shared_ptr<Player>> &GetPlayers() const;

    void SetPlayers(std::deque<std::shared_ptr<Player>> &players);

    const std::deque<std::shared_ptr<Lane>> &GetLanes() const;

    void SetLanes(const std::deque<std::shared_ptr<Lane>> &lanes);

    Field(ppp::Vec3F ,std::uint8_t, double ratio = 0.2);

    void MovePlayer(int);

    void SetOnLane(std::shared_ptr<Player>, std::uint8_t);

    std::uint8_t GetOnLane(std::shared_ptr<Player>);

private:
    std::deque<std::shared_ptr<Lane>> lanes; // deque because of regularly deletion and creation
    std::deque<std::shared_ptr<Player>> players;
    std::shared_ptr<Player> user;
    void idk();
};


#endif //GP_FIELD_H
