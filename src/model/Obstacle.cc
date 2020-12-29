//
// Created by Phili on 11/11/2020.
//

#include "Obstacle.h"

logic::OCube::OCube(glm::vec3 pos, glm::vec3 size) : Obstacle(pos, size) {

}

logic::Obstacle::Obstacle(glm::vec3 pos, glm::vec3 size) : Entity(pos, size) {

}
logic::Ramp1::Ramp1(glm::vec3 pos) : Obstacle(pos , {2, .75, 2}){

}
logic::Ramp2::Ramp2(glm::vec3 pos) : Obstacle(pos , {2, 1.5, 2}){

}
logic::Horde::Horde(glm::vec3 pos) : Obstacle(pos , {1.5, 0.75, 0.3}){

}
