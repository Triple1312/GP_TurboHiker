//
// Created by ppp on 1/1/21.
//

#include "GameSettings.h"

GameSettings GameSettings::instance;

GameSettings::GameSettings() {
  playerspeed = 8;
  jumpheight = 2;
  lanes = 5;
  valversnelling = -2;
  enemies = 2;
  chunks = 1000;
}
