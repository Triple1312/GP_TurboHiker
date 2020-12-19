//
// Created by Phili on 11/11/2020.
//

#include "Obstacle.h"

logic::OCube::OCube(glm::vec3 pos, glm::vec3 size) : Obstacle(pos, size) {

}

logic::Obstacle::Obstacle(glm::vec3 pos, glm::vec3 size) : Entity(pos, size) {

}
