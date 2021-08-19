//
// Created by ppp on 1/1/21.
//

#include "GameSettings.h"

GameSettings GameSettings::instance;

GameSettings::GameSettings() {
  playerspeed = 4;
  jumpheight = 2;
  lanes = 5;
  valversnelling = -1;
  enemies = 2;
  chunks = 1000;
  enemyspeed = 2.8f * playerspeed;
  laneWidth = 2;
  laneHeight = 7;
}
