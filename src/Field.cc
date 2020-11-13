//
// Created by Phili on 11/11/2020.
//

#include "Field.h"

void Field::idk() {

}

const std::deque<std::shared_ptr<Player>> &Field::GetPlayers() const {
    return players;
}

void Field::SetPlayers(std::deque<std::shared_ptr<Player>> &players) {
    Field::players = players;
}

const std::deque<std::shared_ptr<Lane>> &Field::GetLanes() const {
    return lanes;
}

void Field::SetLanes(const std::deque<std::shared_ptr<Lane>> &lanes) {
    Field::lanes = lanes;
}

Field::Field(std::uint8_t lanes) {
    for (int i = 0; i < lanes ; i++ ) {
        this->lanes.emplace_back(std::make_shared<Lane>( 100 + i * 150 ));
    }
    std::deque<std::shared_ptr<Player>> temp;
    auto test = std::make_shared<Player>(sf::Vector3f(600, 400, 50));
    SetOnLane(test, 3);
    temp.push_back(test);
    this->SetPlayers({temp});
    std::cout << "bla" << std::endl;
}

void Field::MovePlayer(int i) {
    auto p = this->players[0];
    auto l = GetOnLane(p);
    if (l == 0 and i == -1) {
        return;
    }
    else if(l == this->lanes.size()-1 and i == 1) {
        return;
    }
    SetOnLane(p, l + i);
}

void Field::SetOnLane(std::shared_ptr<Player> p, std::uint8_t nr) {
    p->SetPosition(sf::Vector3f(this->lanes[nr]->GetLaneChunks()[0]->shape->getPosition().x,
                                this->lanes[nr]->GetLaneChunks()[0]->shape->getPosition().y,
                                0));
}

std::uint8_t Field::GetOnLane(std::shared_ptr<Player> p) {
    for (int i = 0; i < this->lanes.size(); i++) {
        if (this->lanes[i]->GetLaneChunks()[0]->shape->getPosition().x == p->GetShape()->getPosition().x) {
            return i;
        }
    }

    return -1;
}
