//
// Created by Phili on 11/11/2020.
//

#include "World.h"
#include "model/EntityFactory.hh"

const std::deque<std::shared_ptr<logic::Player>> &logic::World::GetPlayers() const {
    return players;
}

void logic::World::SetPlayers(std::deque<std::shared_ptr<Player>> &players) {
    World::players = players;
}

const std::deque<std::shared_ptr<logic::Lane>> &logic::World::GetLanes() const {
    return lanes;
}

void logic::World::SetLanes(const std::deque<std::shared_ptr<Lane>> &lanes) {
    World::lanes = lanes;
}

logic::World::World(std::uint8_t lanes) {
    unsigned char x_size = 2 + lanes * 2 ;
    this->SetPosition(glm::vec3(0,0,50), glm::vec3(x_size, x_size, 100));
    for (int i = 0; i < lanes; i++) {
        this->lanes.emplace_back(
                EntityFactory::Get()->MakeLane(glm::vec3(2+2*i, 0, 0 ),
                                               glm::vec3(2, 1, 100 ) ) );
    }

    this->user = EntityFactory::Get()->MakeUser();
}

void logic::World::MovePlayer(int i) {
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

void logic::World::SetOnLane(std::shared_ptr<Player> p, std::uint8_t nr) { //todo zet niet op grond
    REQUIRE(p.get() != nullptr, "Tried to set an Player that doesnt exist on a lane ");
    REQUIRE(this->lanes.size() > nr, "Tried to set on a lane that doesnt exist");
    REQUIRE(0 <= nr, "Tried to set player on a lane with negative nr");
    //auto test = this->GetLanes()[nr]->GetLaneChunks()[this->GetLanes().size()-1]->GetCenterPos();
    //p->SetPosition(this->GetLanes()[nr]->GetLaneChunks()[0]->GetPos());
}

std::uint8_t logic::World::GetOnLane(std::shared_ptr<Player> p) {
    for (int i = 0; i < this->lanes.size(); i++) {
//        for ( auto j : this->lanes[i]->GetLaneChunks() ) {
//            if (j->Collision(p)) {
//                return i;
//            }
//        }
    }
    ENSURE(false, "player is not found on any lane");
    return -1;
}

void logic::World::Display() {
    for ( auto& i : this->lanes) {
        //std::cout << " glss " << std::flush;
        i->Display();
    }

    this->user->Display();
}

std::shared_ptr<logic::User> logic::World::GetUser() {
    return this->user;
}
