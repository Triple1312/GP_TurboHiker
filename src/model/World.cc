#include "World.h"

#include <utility>

#include "model/Factory.h"

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
    this->lanes_.emplace_back(Factory::Get()->MakeLane(
        glm::vec3(2 + 2 * i, 0, 0), glm::vec3(2, 1, 100)));
  }

  this->user_ = Factory::Get()->MakeUser(
      {this->lanes_[0]->GetPosition().x, this->lanes_[0]->GetPosition().y + 2, 1},
      glm::vec3(1.f));
  this->SetOnLanechunk(this->user_, 2, 1);
  this->players_.emplace_back(this->user_);
  this->user_->velocity_.y = 3;

  // this->lanes_[0]->GetChunks()[6]->SetOnChunk(Factory::Get()->MakeOCube({0,0,0}));
  GenerateObstacleMap();
  for (int i = 0; i < 500; ++i) {
    if (obst_map_[i] != 0) {
      this->obstacles_.emplace_back(Factory::Get()->MakeObstacle(glm::vec3((i % lanes)*2, 1.5f, (i / lanes) * 2),
                                                                 logic::ObstType(obst_map_[i])));
    }

  }
  for (int j = 0; j < 2; j++) {
    std::shared_ptr<NPC> temp = Factory::Get()->MakeNPC({1, 1, 1});
    SetOnLanechunk(temp, j, 1);
    players_.emplace_back(temp);
  }
  // this->user_->SetPosition({this->lanes_[0]->GetPosition().x,
  // this->lanes_[0]->GetPosition().y + 2, 1});

}

void logic::World::MovePlayer(int i) {
  auto p = this->players_[0];
}

void logic::World::SetOnLane(const std::shared_ptr<Player> &p,
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
  for (auto &k : this->players_) {
    k->Display();
  }

  this->user_->Display();
}

std::shared_ptr<logic::User> logic::World::GetUser() { return this->user_; }

void logic::World::Update() {
  this->Display();
  for (const auto &i : this->players_) {
    for (const auto &j : lanes_) {
      for (const auto &k : j->GetChunks()) {
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
    for (const auto &l : obstacles_) {
      glm::vec3 tmp = i->Collision(l);

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
  for (int b = 0; b < this->players_.size() - 1; b++) {
    for (int c = b + 1; c < this->players_.size(); c++) {
      auto tmp = this->players_[b]->Collision(players_[c]);
      if (tmp != glm::vec3(0.f)) {
        auto b_stamina = players_[b]->stamina_;
        auto c_stamina = players_[c]->stamina_;
        players_[b]->Bump(c_stamina, tmp);
        players_[c]->Bump(b_stamina, -tmp);
      }
    }

  }

}

void logic::World::SetOnLanechunk(std::shared_ptr<logic::Entity> entity,
                                  unsigned int lane, unsigned int chunk) {
  this->lanes_[lane]->SetOnChunk(entity, chunk);
}
void logic::World::Generate(uint8_t lane_count) {

  int max = lane_count / 2; // afronden naar beneden
  int length = 100;
  int field[lane_count][100];
  for (int l = 0; l < lane_count; ++l) {
    field[l][0] = 0;
  }

//  for (int i = 1; i < length; i++) {
//
//  }
  float atm = 0;

}
void logic::World::GenerateObstacleMap() {
  obst_map_.resize(500, 0 );
  std::uint8_t lanes = 5;
  for (int i = 8; i < 500; i++) {
    if (obst_map_[i - lanes] == 2) {
      obst_map_[i] = 0;
    } else if (obst_map_[i - lanes] == 3) {
      obst_map_[i] = 4;
    } else if (obst_map_[i - lanes] == 4) {
      obst_map_[i] = 1;
    } else {
      std::vector<std::uint8_t> temp = {0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 3, 0};
      if (obst_map_[i - lanes] == 1) {
        temp.emplace_back(1);
        temp.emplace_back(1);
        temp.emplace_back(1);
      } else if (obst_map_[i - lanes - 1] == 1 || obst_map_[i - lanes + 1] == 1) {

      } else {
        temp.emplace_back(1);
        temp.emplace_back(1);
      }
      auto r = Random::Get().Int(0, temp.size() - 1);
      obst_map_[i] = temp[r];

    }

  }
}
