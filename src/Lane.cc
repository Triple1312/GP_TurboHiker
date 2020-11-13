//
// Created by Phili on 11/11/2020.
//

#include "Lane.h"


Lane::Lane(double x_pos) {
    for (int i = 0; i < 5; i++) {
        auto chunk = std::make_shared<LaneChunk>();
        chunk->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(50.f, 100.f));
        chunk->shape->setFillColor(sf::Color::Red);
        chunk->shape->setPosition(x_pos, i * 100.f);
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
    this->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(50, 100));
    this->shape->setFillColor(sf::Color::Red);
}
