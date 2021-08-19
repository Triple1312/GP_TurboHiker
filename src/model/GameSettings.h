

#ifndef GP_SRC_MODEL_GAMESETTINGS_H_
#define GP_SRC_MODEL_GAMESETTINGS_H_
#include <memory>

struct GameSettings {
 public:
  static float PlayerSpeed() { return instance.playerspeed; }

  static float JumpHeight() { return instance.jumpheight; }

  static uint8_t Lanes() { return instance.lanes; }

  static uint8_t Enemies() { return instance.enemies; }

  static uint32_t Chunks() { return instance.chunks; }

  static float LaneWidth() {return instance.laneWidth; }

  static float LaneHeight() {return instance.laneHeight; }

  static float EnemySpeed() { return instance.enemyspeed; }

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
