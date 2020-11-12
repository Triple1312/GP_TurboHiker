//
// Created by Phili on 11/11/2020.
//

#ifndef GP_FIELD_H
#define GP_FIELD_H

#include <memory>
#include <vector>
#include <deque>

#include "Widget.h"
#include "Lane.h"
#include "Entity.h"
#include "Player.h"


class Field : public Widget{
    //std::map<int, std::shared_ptr<Entity>> lanes;
    std::vector<std::shared_ptr<Player>> players;
public:
    const std::vector<std::shared_ptr<Player>> &GetPlayers() const;

    void SetPlayers(const std::vector<std::shared_ptr<Player>> &players);

    const std::deque<Lane> &GetLanes() const;

    void SetLanes(const std::deque<Lane> &lanes);

private:
    std::deque<Lane> lanes; // deque because of regularly deletion and creation
    void idk();
};


#endif //GP_FIELD_H
