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
  lanes = GameSettings::Lanes();
  unsigned char x_size = 2 + lanes * 2;
  this->SetPosition(glm::vec3(0, 0, 50), glm::vec3(x_size, x_size, 100));
  for (int i = 0; i < lanes; i++) {
    this->lanes_.emplace_back(Factory::Get()->MakeLane(
        glm::vec3(2 * i, 0 + .5f, 250), glm::vec3(2, 1, 500)));
  }

  this->user_ =
      Factory::Get()->MakeUser({this->lanes_[0]->GetPosition().x,
                                this->lanes_[0]->GetPosition().y + 2, 1},
                               glm::vec3(1.f));
  this->SetOnLanechunk(this->user_, 2, 1);
  this->players_.emplace_back(this->user_);

  this->score_board_ = Factory::Get()->MakeScoreBoard(this->user_);

  // this->lanes_[0]->GetChunks()[6]->SetOnChunk(Factory::Get()->MakeOCube({0,0,0}));
  GenerateObstacleMap();
  for (int i = 0; i < GameSettings::Chunks(); ++i) {
    if (obst_map_[i] != 0) {
      this->obstacles_.emplace_back(Factory::Get()->MakeObstacle(
          glm::vec3((i % lanes) * 2, 0, (i / lanes) * 2),
          logic::ObstType(obst_map_[i])));
    }
  }
  for (int j = 0; j < GameSettings::Enemies(); j++) {
    std::shared_ptr<NPC> temp = Factory::Get()->MakeNPC({1, 1, 1});
    SetOnLanechunk(temp, j, 1);
    players_.emplace_back(temp);
  }
  // this->user_->SetPosition({this->lanes_[0]->GetPosition().x,
  // this->lanes_[0]->GetPosition().y + 2, 1});
}

void logic::World::MovePlayer(int i) { auto p = this->players_[0]; }

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

void collision(logic::Player* e1, logic::Entity* e2){
  glm::vec3 tmp = e1->Collision(e2);


  if (tmp.x != 0.F) {  // if there is no collision it will also end here
    e1->MoveRight(tmp.x);

  } else if (tmp.y != 0.F) {
    e1->MoveUp(tmp.y);
    e1->velocity_.y = 0.f;
    e1->airborne_ = false;
  } else if (tmp.z != 0.F) {
    e1->velocity_.z = GameSettings::PlayerSpeed() * 3 / 4;
    e1->MoveForward(tmp.z);
  }
}

void logic::World::Update() {
  this->Display();
  for (const auto &i : this->players_) {
    auto l1 = [&](Player& player){
      P_L_Collision(player);
    };
//
//    auto pppp = l1[i];

    std::vector<std::thread> threads;
    
    for (const auto &l : obstacles_) {
      threads.emplace_back(std::thread(collision,i.get(),l.get()));
//      glm::vec3 tmp = i->Collision(l.get());
//
//
//      if (tmp.x != 0.F) {  // if there is no collision it will also end here
//        i->MoveRight(tmp.x);
//
//      } else if (tmp.y != 0.F) {
//        i->MoveUp(tmp.y);
//        i->velocity_.y = 0.f;
//        i->airborne_ = false;
//      } else if (tmp.z != 0.F) {
//        this->velocity_.z = GameSettings::PlayerSpeed() * 3 / 4;
//        i->MoveForward(tmp.z);
//      }
    }

    for (const auto &l : lanes_) {//todo collision multi ??
      threads.emplace_back(std::thread(collision,i.get(),l.get()));
//      glm::vec3 tmp = i->Collision(l.get());
//      if (tmp.x != 0.F) {  // if there is no collision it will also end here
//        i->MoveRight(tmp.x);
//
//      } else if (tmp.y != 0.F) {
//        i->MoveUp(tmp.y);
//        i->velocity_.y = 0.f;
//        i->airborne_ = false;
//      } else if (tmp.z != 0.F) {
//        this->velocity_.z = GameSettings::PlayerSpeed() * 3 / 4;
//        i->MoveForward(tmp.z);
//      }
    }
    for (auto &th : threads) {
      th.join();
    }

  }
  for (int b = 0; b < this->players_.size() - 1; b++) {
    for (int c = b + 1; c < this->players_.size(); c++) {
      auto tmp = this->players_[b]->Collision(players_[c].get());
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
                                  unsigned int lane, unsigned int chunk) {}
void logic::World::Generate(uint8_t lane_count) {
  int max = GameSettings::Lanes() / 2;  // afronden naar beneden
  int length = 100;
  int field[GameSettings::Lanes()][500];
  for (int l = 0; l < GameSettings::Lanes(); ++l) {
    field[l][0] = 0;
  }

  //  for (int i = 1; i < length; i++) {
  //
  //  }
  float atm = 0;
}

/*
 * function generates the obstacles on the map.
 * first it checks which obstacles can be placed on which chunks
 * it puts all the possibilities in a vector (with the amount specified)
 * then it chooses one of the possibilities random and places it on the map
 */
void logic::World::GenerateObstacleMap() {
  obst_map_.resize(GameSettings::Chunks(), 0);
  std::uint8_t lanes = 5;
  for (int i = 8; i < GameSettings::Chunks(); i++) {
    if (obst_map_[i - lanes] == 3) {
      obst_map_[i] = 4;
    } else if (obst_map_[i - lanes] == 4) {
      obst_map_[i] = 1;
    } else {
      std::vector<std::uint8_t> temp;
      if (obst_map_[i - lanes - 1] == 1 || obst_map_[i - lanes + 1] == 1) {
        temp = {0};
      } else if (obst_map_[i - lanes] == 1) {
        temp = {0, 0, 0, 0, 0, 1, 1, 1, 0};
      } else if (obst_map_[i - lanes] != 0) {
        temp = {0};
      } else {
        for (int j = 0; j < 3; ++j) {
          temp.emplace_back(1);
        }
        //        for (int j = 0; j < 1; ++j) {
        //          temp.emplace_back(3);
        //        }
        for (int j = 0; j < 2; ++j) {
          temp.emplace_back(2);
        }
        for (int j = 0; j < 30; ++j) {
          temp.emplace_back(0);
        }
        for (int j = 0; j < 1; ++j) {
          temp.emplace_back(4); //todo dit moet 5 zijn
        }
      }
      auto r = Random::Get().Int(0, temp.size() - 1);
      obst_map_[i] = temp[r];
    }
  }
}
logic::Scoreboard *logic::World::GetScoreBoard() {
  return this->score_board_.get();
}
void logic::World::P_L_Collision(logic::Player &player) {
  for (const auto &j : lanes_) {
    glm::vec3 tmp = player.Collision(j.get());
    if (tmp.x != 0.F) {  // if there is no collision it will also end here
      player.MoveRight(tmp.x);
    } else if (tmp.y != 0.F) {
      player.MoveUp(tmp.y);
      player.velocity_.y = 0.f;
      player.airborne_ = 0;
    } else if (tmp.z != 0.F) {
      player.MoveForward(tmp.z);
    }
  }
}
