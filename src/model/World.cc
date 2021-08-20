#include "World.h"
#include "model/Factory.h"

const std::deque<std::shared_ptr<logic::Player>> &logic::World::GetPlayers()
    const {
  return players_;
}

const std::deque<std::shared_ptr<logic::Lane>> &logic::World::GetLanes() const {
  return lanes_;
}

logic::World::World(std::uint8_t lanes) {
  Clock::Get()->Reset();
  lanes = GameSettings::GetLanes();
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

  this->players_.emplace_back(this->user_);

  this->score_board_ = Factory::Get()->MakeScoreBoard(this->user_);


  GenerateObstacleMap();
  for (int i = 0; i < GameSettings::GetChunks(); ++i) {
    if (obst_map_[i] != 0) {
      this->obstacles_.emplace_back(Factory::Get()->MakeObstacle(
          glm::vec3((i % lanes) * 2, 0, (i / lanes) * 2),
          logic::ObstType(obst_map_[i])));
    }
  }
  this->obstacles_.emplace_back(Factory::Get()->MakeObstacle({lanes, 0.7, 430}, FINISH));

  for (int j = 0; j < GameSettings::GetEnemies(); j++) {
    std::shared_ptr<NPC> temp = Factory::Get()->MakeNPC({1, 1, 1});
    temp->SetPosition({2* (j+1), 2, 1});
    players_.emplace_back(temp);
  }

  int eek = GameSettings::GetEnemies()*2;
  for (int k = 1; k < eek;k++) {
    int lane = Random::Get().Int(0, GameSettings::GetLanes());
    std::shared_ptr<logic::KillerNPC> temp = Factory::Get()->MakeKillerNPC(glm::vec3(lane*2, 3, 90+ 400/k));
    players_.emplace_back(temp);
  }
}

void logic::World::Display() {
  if(this->user_->finished_ || this->user_->dead){this->score_board_->Draw(); return;}
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
  this->score_board_->Draw();


}

std::shared_ptr<logic::User> logic::World::GetUser() { return this->user_; }

void collision(logic::Player* e1, logic::Entity* e2){
  glm::vec3 tmp = e1->Collision(e2);


  if (tmp.x != 0.F) {  // if there is no collision it will also end here
    e1->MoveRight(tmp.x);
    e1->Modify(e2->Hit());
    e2->Modify(e1->Hit());

  } else if (tmp.y != 0.F) {

    e1->MoveUp(tmp.y);
    e1->Modify(e2->Hit());
    e1->velocity_.y = 0.f;
    e1->airborne_ = false;
  } else if (tmp.z != 0.F) {
    e1->velocity_.z = GameSettings::GetPlayerSpeed() * 3 / 4;
    e1->MoveForward(tmp.z);
    e1->Modify(e2->Hit());
    e2->Modify(e1->Hit());
  }

}

void logic::World::Update() {
  if(this->user_->finished_) {
    this->score_board_->Finish();
    return;
  }
  if(this->user_->dead) {
    this->score_board_->Finish();
    return;
  }

  this->Display();

  for (auto i = this->players_.begin(); i != this->players_.end(); i++) {

    if (i->get()->dead) {
      this->players_.erase(i);
    }

    std::vector<std::thread> threads;

    for(auto p = this->players_.begin(); p != this->players_.end(); p++) {
      if(p->get() != i->get()) {
        threads.emplace_back(std::thread(collision,i->get(),p->get()));
      }
    }
    
    for (const auto &l : obstacles_) {
      threads.emplace_back(std::thread(collision,i->get(),l.get()));
    }

    for (const auto &l : lanes_) {//todo collision multi ??
      threads.emplace_back(std::thread(collision,i->get(),l.get()));
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

void logic::World::Generate() {
  int field[GameSettings::GetLanes()][500];
  for (int l = 0; l < GameSettings::GetLanes(); ++l) {
    field[l][0] = 0;
  }

}

/*
 * function generates the obstacles on the map.
 * first it checks which obstacles can be placed on which chunks
 * it puts all the possibilities in a vector (with the amount specified)
 * then it chooses one of the possibilities random and places it on the map
 */
void logic::World::GenerateObstacleMap() {
  obst_map_.resize(GameSettings::GetChunks(), 0);
  std::uint8_t lanes = GameSettings::GetLanes();
  for (int i = 8; i < GameSettings::GetChunks(); i++) {
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

        for (int j = 0; j < 2; ++j) {
          temp.emplace_back(2);
        }
        for (int j = 0; j < 30; ++j) {
          temp.emplace_back(0);
        }
        for (int j = 0; j < 1; ++j) {
          temp.emplace_back(5);
        }
      }
      auto r = Random::Get().Int(0, temp.size() - 1);
      obst_map_[i] = temp[r];
    }
  }
}
