

#include "Collectable.h"
logic::Collectable::Collectable(glm::vec3 pos) : Obstacle(pos + glm::vec3(0, .5, 0), {.5, .5, .5}) {};

logic::Modifier logic::Collectable::Hit() {
  u_int8_t type = Random::Get().Int(0,3);
  if (type == 0) {
    return {glm::vec3(0, GameSettings::GetJumpHeight() * 3, 0), 0, false, false, false, false, 0};
  }
  if (type == 1) {
    return {glm::vec3(0, 0, GameSettings::GetPlayerSpeed() * 1.3), 0, false, false, false, false, 0};
  }
  if (type == 2) {
    return {glm::vec3(0, 0, 0), 5000, false, false, false, false, 0};
  }
  if (type == 3) {
    return {glm::vec3(0, 0, GameSettings::GetPlayerSpeed() * 1.3), 0, false, false, false, false, 1};
  }
  logic::Modifier ret  = {glm::vec3(0, GameSettings::GetJumpHeight() * 3, 0), 0, false, false, false, false, 0};
  return ret;
}
