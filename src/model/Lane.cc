#include "Lane.h"
#include "Factory.h"


logic::Lane::Lane(glm::vec3 pos, glm::vec3 size) : Entity(glm::vec3(pos.x, pos.y-size.y, pos.z), size) {

}
