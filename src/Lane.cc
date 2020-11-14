//
// Created by Phili on 11/11/2020.
//

#include "Lane.h"


Lane::Lane(double x_pos, double width) {
    for (int i = 0; i < 5; i++) {
        auto chunk = std::make_shared<LaneChunk>();
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
    this->size = ppp::Vec3F(50, 1, 100);
}

Lane::LaneChunk::LaneChunk(ppp::Vec3F p, ppp::Vec3F s) {
    this->pos = p;
    this->size = ppp::Vec3F(50, 100, 100);
}
