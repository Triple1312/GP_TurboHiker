//
// Created by phil on 7/29/21.
//

#include "Collectable.h"
Collectable::Collectable(glm::vec3 pos) : Obstacle(pos + glm::vec3(0, .5, 0), {.5, .5, .5}) {};

Modifier Collectable::Hit() {
  return Modifier(glm::vec3(0, 25, 0), 0);
}
