#ifndef GP_WORLD_H
#define GP_WORLD_H

#include <memory>
#include <vector>
#include <deque>
#include <iostream>

#include "Widget.h"
#include "Lane.h"
#include "Entity.h"
#include "Player.h"
#include "DisignByContract.h"

namespace logic {

class World : public Entity {
public:

    const std::deque<std::shared_ptr<Player>> &GetPlayers() const;

    void SetPlayers(std::deque<std::shared_ptr<Player>> &players);

    const std::deque<std::shared_ptr<Lane>> &GetLanes() const;

    void SetLanes(const std::deque<std::shared_ptr<Lane>> &lanes);

    World(std::uint8_t);

    void MovePlayer(int);

    void SetOnLane(std::shared_ptr<Player>, std::uint8_t);

    std::uint8_t GetOnLane(std::shared_ptr<Player>);

    void Display() override;

    std::shared_ptr<logic::User> GetUser();



private:
    std::deque<std::shared_ptr<Lane>> lanes; // deque because of regularly deletion and creation
    std::deque<std::shared_ptr<Player>> players;
    std::shared_ptr<logic::User> user;

};

}

#endif //GP_WORLD_H
