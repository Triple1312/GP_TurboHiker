//
// Created by Phili on 11/11/2020.
//

#include "Field.h"

void Field::idk() {

}

const std::vector<std::shared_ptr<Player>> &Field::GetPlayers() const {
    return players;
}

void Field::SetPlayers(const std::vector<std::shared_ptr<Player>> &players) {
    Field::players = players;
}

const std::deque<Lane> &Field::GetLanes() const {
    return lanes;
}

void Field::SetLanes(const std::deque<Lane> &lanes) {
    Field::lanes = lanes;
}
