

#ifndef GP_SRC_MODEL_GAMESETTINGS_H_
#define GP_SRC_MODEL_GAMESETTINGS_H_
#include <memory>
#include <fstream>

#include "Utils/json.hpp"

struct GameSettings {
 public:
  static float GetPlayerSpeed() { return instance.playerspeed; }

  static float GetJumpHeight() { return instance.jumpheight; }

  static uint8_t GetLanes() { return instance.lanes; }

  static uint8_t GetEnemies() { return instance.enemies; }

  static uint32_t GetChunks() { return instance.chunks; }

  static float GetLaneWidth() {return instance.laneWidth; }

  static float LaneHeight() {return instance.laneHeight; }

  static float GetEnemySpeed() { return instance.enemyspeed; }

 private:
  static GameSettings instance;

  GameSettings();

  float playerspeed;
  float jumpheight;
  uint8_t lanes;
  float valversnelling;
  uint8_t enemies;
  uint32_t chunks;
  float enemyspeed;
  float laneWidth;
  float laneHeight;
};

#endif  // GP_SRC_MODEL_GAMESETTINGS_H_
