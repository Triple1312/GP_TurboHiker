//
// Created by Phili on 11/11/2020.
//

#include "Lane.h"


Lane::Lane(double x_pos, glm::vec4 space, double size) {
    for (int i = 0; i < 10; i++) {
        auto chunk = std::make_shared<LaneChunk>(glm::vec4(x_pos, 0.1, size * i, 1), glm::vec4(size, size, size, 0));
        this->lane_chunks.push_back(chunk);
    }

}

const std::deque<std::shared_ptr<Lane::LaneChunk>> &Lane::GetLaneChunks() const {
    return lane_chunks;
}


//void Lane::SetLaneChunks(const std::deque<Lane::LaneChunk> &laneChunks) {
//    lane_chunks = laneChunks;
//}
Lane::LaneChunk::LaneChunk() {
    this->size = glm::vec4(50, 100, 100, 0);
}

Lane::LaneChunk::LaneChunk(glm::vec4 p, glm::vec4 s) {
    this->pos = p;
    this->size = s; //glm::vec4(50, 100, 100);
}
