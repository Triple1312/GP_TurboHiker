//
// Created by Phili on 11/11/2020.
//

#include "Lane.h"


Lane::Lane(double x_pos, double width) {
    for (int i = 0; i < 5; i++) {
        auto chunk = std::make_shared<LaneChunk>();
        chunk->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, 100.f));
        chunk->shape->setFillColor(sf::Color::Red);
        chunk->shape->setOutlineThickness(1);
        chunk->shape->setOutlineColor(sf::Color::White);
        chunk->shape->setPosition(x_pos, i * 100.f);
        this->lane_chunks.push_back(chunk);
    }

}

const std::deque<std::shared_ptr<Lane::LaneChunk>> &Lane::GetLaneChunks() const {
    return lane_chunks;
}

std::uint8_t Lane::GetCenterX() {
    return this->lane_chunks[0]->GetCenterX();
}

std::uint8_t Lane::GetCenterY() {
    return this->lane_chunks[0]->GetCenterY();
}

//void Lane::SetLaneChunks(const std::deque<Lane::LaneChunk> &laneChunks) {
//    lane_chunks = laneChunks;
//}
Lane::LaneChunk::LaneChunk() {
    this->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(50, 100));
    this->shape->setFillColor(sf::Color::Red);
    this->shape->setOutlineColor(sf::Color::White);
    this->shape->setOutlineThickness(10);
}

std::uint8_t Lane::LaneChunk::GetCenterX() {
    return (this->shape->getPosition().x + this->shape->getSize().x / 2);
}

std::uint8_t Lane::LaneChunk::GetCenterY() {
    return (this->shape->getPosition().y + this->shape->getSize().y / 2);
}

sf::Vector2f Lane::LaneChunk::GetCenter() {
    return  this->shape->getPosition() + this->shape->getSize()/2.f;
}
