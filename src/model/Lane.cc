#include "Lane.h"
#include "EntityFactory.hh"

//const std::deque<std::shared_ptr<model::Lane::LaneChunk>> &model::Lane::GetLaneChunks() const {
//    return lane_chunks;
//}

//logic::Lane::Lane(glm::vec3 pos, double count, glm::vec3 size) {
//    for (int i = 0; i < count; i++) {
//        this->lane_chunks.emplace_back(LaneChunk(glm::vec3(pos.x, pos.y, pos.z + i * size.z ), size));
//    }
//}

logic::Lane::Lane(glm::vec3 pos, glm::vec3 size) {
    for (int i = 0; i * size.x <= size.z ; i++ ) {
        this->lane_chunks.emplace_back(
                (logic::EntityFactory::Get()->MakeLaneChunk(
                        glm::vec3(pos.x, pos.y, pos.z + pos.z * i),
                        glm::vec3(size.x, size.y,size.x ) ) ) ) ;
    }
}

void logic::Lane::Display() {
    std::cout << "bjdf";
    for ( auto &i : this->lane_chunks ) {
        std::cout << "bjdf";
        i->Display();
    }
}

//model::Lane::LaneChunk::LaneChunk(glm::mat4 model = glm::mat4(1.0f)) {
//
//}

//logic::LaneChunk::LaneChunk(glm::vec3 pos, glm::vec3 size) {
//    // todo use random to make obstacle
//}

logic::LaneChunk::LaneChunk(glm::vec3 pos, glm::vec3 size) : Entity(pos, size) {

}
