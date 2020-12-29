#ifndef GP_SRC_MODEL_WORLD_H_
#define GP_SRC_MODEL_WORLD_H_

#include <memory>
#include <vector>
#include <deque>
#include <iostream>

#include "Lane.h"
#include "Entity.h"
#include "Player.h"
#include "DisignByContract.h"
#include "Utils/Random.hpp"

namespace logic {

class World : public Entity {
 public:

  const std::deque<std::shared_ptr<Player>> &GetPlayers() const;

  void SetPlayers(std::deque<std::shared_ptr<Player>> &players);

  const std::deque<std::shared_ptr<Lane>> &GetLanes() const;

  void SetLanes(const std::deque<std::shared_ptr<Lane>> &lanes);

  explicit World(std::uint8_t);

  void Generate(uint8_t lane_count);

  void MovePlayer(int);

  void SetOnLane(const std::shared_ptr<Player>&, std::uint8_t);

  std::uint8_t GetOnLane(std::shared_ptr<Player>);

  void Display() override;

  std::shared_ptr<logic::User> GetUser();

  void Update();

  void SetOnLanechunk(std::shared_ptr<logic::Entity>, unsigned int, unsigned int);

 private:
  std::deque<std::shared_ptr<Lane>> lanes_; // deque because of regularly deletion and creation
  std::deque<std::shared_ptr<Player>> players_;
  std::shared_ptr<logic::User> user_;
  std::deque<std::shared_ptr<logic::Obstacle>> obstacles_;

  std::vector<std::uint8_t> obst_map_;

  void GenerateObstacleMap();


};

} // namespace logic

#endif //GP_SRC_MODEL_WORLD_H_
