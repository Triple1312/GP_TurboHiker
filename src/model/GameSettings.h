

#ifndef GP_SRC_MODEL_GAMESETTINGS_H_
#define GP_SRC_MODEL_GAMESETTINGS_H_
#include <memory>

struct GameSettings {
 public:

  static float PlayerSpeed() {return instance.playerspeed;}

  static float JumpHeight() {return instance.jumpheight;}

  static uint8_t Lanes() { return instance.lanes;}

  static uint8_t Enemies() { return instance.enemies;}

  static uint32_t Chunks() { return instance.chunks;}



 private:
  static GameSettings instance;

  GameSettings();

  float playerspeed;
  float jumpheight;
  uint8_t lanes;
  float valversnelling;
  uint8_t enemies;
  uint32_t chunks;


};

#endif //GP_SRC_MODEL_GAMESETTINGS_H_
