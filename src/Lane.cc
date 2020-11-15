//
// Created by Phili on 11/11/2020.
//

#include "Lane.h"


Lane::Lane(double x_pos, ppp::Vec3F space) {
    for (int i = 0; i < 5; i++) {
        auto chunk = std::make_shared<LaneChunk>(ppp::Vec3F(x_pos, 200 * space.y /600, 100 * space.z/600 * i));
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
    this->size = ppp::Vec3F(50, 100, 100);
}

Lane::LaneChunk::LaneChunk(ppp::Vec3F p, ppp::Vec3F s) {
    this->pos = p;
    this->size = s; //ppp::Vec3F(50, 100, 100);
}
