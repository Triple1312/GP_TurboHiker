//
// Created by ppp on 1/1/21.
//

#include "GameSettings.h"

GameSettings GameSettings::instance;

GameSettings::GameSettings() {
  std::ifstream settingsfile("gamedata.json");
  nlohmann::json j;
  j << settingsfile;
  playerspeed = j["playerspeed"];
  jumpheight = j["jumpheight"];
  lanes = j["lanes"];
  valversnelling = -1;
  enemies = j["enemies"];
  chunks = j["chunks"];
  enemyspeed = ((float)j.at("playerspeed") * (float)j.at("enemyspeedmultiplier"));
  laneWidth = 2;
  laneHeight = 7;
}
