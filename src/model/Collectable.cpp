//
// Created by phil on 7/29/21.
//

#include "Collectable.h"
logic::Collectable::Collectable(glm::vec3 pos) : Obstacle(pos + glm::vec3(0, .5, 0), {.5, .5, .5}) {};

logic::Modifier logic::Collectable::Hit() {
  u_int8_t type = Random::Get().Int(0,2);
  if (type == 0) {
    return {glm::vec3(0, GameSettings::JumpHeight() * 3, 0), 0};
  }
  if (type == 1) {
    return {glm::vec3(0, 0, GameSettings::PlayerSpeed() * 1.3), 0};
  }
  logic::Modifier ret  = {glm::vec3(0, GameSettings::JumpHeight() * 3, 0), 0};
  return ret;
}
