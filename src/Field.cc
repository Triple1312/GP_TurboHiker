//
// Created by Phili on 11/11/2020.
//

#include "Field.h"

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

Field::Field(ppp::Vec3F space, std::uint8_t lanes , double ratio ) {
    float z = space.z /(lanes  / ratio + lanes-1);
    float x = z / ratio;

    for (int i = 0; i < lanes ; i++ ) {
        auto meh = i* (x+z);
        this->lanes.emplace_back(std::make_shared<Lane>( i* (x+z), space));
    }
    std::deque<std::shared_ptr<Player>> temp;
    auto test = std::make_shared<Player>(this->lanes[4]->GetLaneChunks()[0]->GetPos());//, this->lanes[3]->GetLaneChunks()[0]->size * 0.75);
    //test->SetCenterPos(this->lanes[4]->GetLaneChunks()[0]->GetCenterPos());
    this->user = test;
    SetOnLane(test, 3);
    auto ent = *test.get();

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
    REQUIRE(p.get() != nullptr, "Tried to set an Player that doesnt exist on a lane ");
    REQUIRE(this->lanes.size() > nr, "Tried to set on a lane that doesnt exist");
    REQUIRE(0 <= nr, "Tried to set player on a lane with negative nr");
    auto test = this->GetLanes()[nr]->GetLaneChunks()[this->GetLanes().size()-1]->GetCenterPos();
    p->SetPosition(this->GetLanes()[nr]->GetLaneChunks()[0]->GetPos());

}

std::uint8_t Field::GetOnLane(std::shared_ptr<Player> p) {
    for (int i = 0; i < this->lanes.size(); i++) {
        for ( auto j : this->lanes[i]->GetLaneChunks() ) {
            if (j->Collision(p)) {
                return i;
            }
        }
    }
    ENSURE(false, "player is not found on any lane");
    return -1;
}
