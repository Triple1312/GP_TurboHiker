//
// Created by Phili on 11/11/2020.
//

#include "World.h"

#include <utility>

#include "model/EntityFactory.hh"

const std::deque<std::shared_ptr<logic::Player>> &logic::World::GetPlayers()
const {
  return players_;
}

void logic::World::SetPlayers(std::deque<std::shared_ptr<Player>> &players) {
  World::players_ = players;
}

const std::deque<std::shared_ptr<logic::Lane>> &logic::World::GetLanes() const {
  return lanes_;
}

void logic::World::SetLanes(const std::deque<std::shared_ptr<Lane>> &lanes) {
  World::lanes_ = lanes;
}

logic::World::World(std::uint8_t lanes) {
  unsigned char x_size = 2 + lanes * 2;
  this->SetPosition(glm::vec3(0, 0, 50), glm::vec3(x_size, x_size, 100));
  for (int i = 0; i < lanes; i++) {
    this->lanes_.emplace_back(EntityFactory::Get()->MakeLane(
        glm::vec3(2 + 2 * i, 0, 0), glm::vec3(2, 1, 100)));
  }

  this->user_ = EntityFactory::Get()->MakeUser(
      {this->lanes_[0]->GetPosition().x, this->lanes_[0]->GetPosition().y + 2, 1},
      glm::vec3(1.f));
  this->SetOnLanechunk(this->user_, 2, 1);
  this->players_.emplace_back(this->user_);
  this->user_->velocity_.y = 3;

  // this->lanes_[0]->GetChunks()[6]->SetOnChunk(EntityFactory::Get()->MakeOCube({0,0,0}));

  for (int i = 0; i < 12; i++) {
    this->obstacles_.emplace_back(EntityFactory::Get()->MakeOCube());
    this->SetOnLanechunk(this->obstacles_[i], Random::Get().Int(0, 4),
                         Random::Get().Int(2, 50));
  }
  for (int j = 0; j < 2; j++) {
    std::shared_ptr<NPC> temp = EntityFactory::Get()->MakeNPC({1, 1, 1});
    SetOnLanechunk(temp , j , 1);
    players_.emplace_back(temp);
  }
  // this->user_->SetPosition({this->lanes_[0]->GetPosition().x,
  // this->lanes_[0]->GetPosition().y + 2, 1});
}

void logic::World::MovePlayer(int i) {
  auto p = this->players_[0];
}

void logic::World::SetOnLane(const std::shared_ptr<Player>& p,
                             std::uint8_t nr) {  // todo zet niet op grond
  REQUIRE(p.get() != nullptr,
          "Tried to set an Player that doesnt exist on a lane ");
  REQUIRE(this->lanes_.size() > nr, "Tried to set on a lane that doesnt exist");
  REQUIRE(0 <= nr, "Tried to set player on a lane with negative nr");
  // auto test =
  // this->GetLanes()[nr]->GetLaneChunks()[this->GetLanes().size()-1]->GetCenterPos();
  // p->SetPosition(this->GetLanes()[nr]->GetLaneChunks()[0]->GetPos());
}

void logic::World::Display() {
  for (auto &i : this->lanes_) {
    // std::cout << " glss " << std::flush;
    i->Display();
  }
  for (auto &j : this->obstacles_) {
    j->Display();
  }
  for ( auto &k : this->players_) {
    k->Display();
  }

  this->user_->Display();
}

std::shared_ptr<logic::User> logic::World::GetUser() { return this->user_; }

void logic::World::Update() {
  this->Display();
  for (const auto& i : this->players_) {
    for (const auto& j : lanes_) {
      for (const auto& k : j->GetChunks()) {
        glm::vec3 tmp = i->Collision(k);
        if (tmp.x != 0.F) {  // if there is no collision it will also end here
          i->MoveRight(tmp.x);
        } else if (tmp.y != 0.F) {
          i->MoveUp(tmp.y);
          i->velocity_.y = 0.f;
        } else if (tmp.z != 0.F) {
          i->MoveForward(tmp.z);
        }
      }
    }
    for (const auto& l : obstacles_) {
      glm::vec3 tmp = i->Collision(l);

      if (tmp.x <= tmp.y &&
          tmp.x <= tmp.z) {  // if there is no collision it will also end here
        i->MoveRight(tmp.x);
      } else if (tmp.y <= tmp.x && tmp.y <= tmp.z) {
        i->MoveUp(tmp.y);
        i->velocity_.y = 0.f;
      } else {
        i->MoveForward(tmp.z);
      }
    }
  }

}

void logic::World::SetOnLanechunk(std::shared_ptr<logic::Entity> entity,
                                  unsigned int lane, unsigned int chunk) {
  this->lanes_[lane]->SetOnChunk(entity, chunk);
}
