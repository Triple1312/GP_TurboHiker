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

Field::Field(std::uint8_t lanes , double ratio ) {
    float y = 600 /(lanes  / ratio + lanes-1);
    float x = y / ratio;
    for (int i = 0; i < lanes ; i++ ) {
        auto meh = 100 + i* (x+y);
        this->lanes.emplace_back(std::make_shared<Lane>(100 + i* (x+y)));
    }
    std::deque<std::shared_ptr<Player>> temp;
    auto test = std::make_shared<Player>(ppp::Vec3F(600, 400, 50));
    this->user = test;
    SetOnLane(test, 3);
    auto ent = *test.get();
    Player a(ppp::Vec3F(3,5,4));
    Entity& b = a;
    if (typeid(b) == typeid(Player)) { //todo

    }
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

void Field::SetOnLane(std::shared_ptr<Player> p, std::uint8_t nr) { //todo zet niet op grond
    auto test = this->GetLanes()[nr]->GetLaneChunks()[this->GetLanes().size()-1]->GetCenterPos();
    p->SetCenterTo(test);

}

std::uint8_t Field::GetOnLane(std::shared_ptr<Player> p) {
    for (int i = 0; i < this->lanes.size(); i++) {
        for ( auto j : this->lanes[i]->GetLaneChunks() ) {
            if (j->Collision(p)) {
                return i;
            }
        }
    }
    return -1;
}
