#include "Entity.h"

glm::vec3 logic::Entity::Collision(std::shared_ptr<Entity> enti) {
  glm::vec3 axis(0.f);
  float depth = INFINITY;

  /// X axis
  float x0 = enti->points_[6 * 3 + 0] - this->points_[0];
  if (x0 < depth) {
    depth = x0;
    axis.x = x0;
  }

  float x1 = this->points_[6 * 3 + 0] - enti->points_[0];
  if (x1 < depth) {
    depth = x1;
    axis.x = x1;
  }

  if (x0 <= 0 || x1 <= 0) {
    return glm::vec3(0.f);
  }

  /// Y axis
  float y0 = enti->points_[6 * 3 + 1] - this->points_[1];
  if (y0 < depth) {
    depth = y0;
    axis.x = 0.f;
    axis.y = y0;
  }

  float y1 = this->points_[6 * 3 + 1] - enti->points_[1];
  if (y1 < depth) {
    depth = y1;
    axis.x = 0.f;
    axis.y = -y1;
  }

  // if ( y0 <= 0 || y1 <= 0 ) {return glm::vec3 (0.f);}

  /// Z axis
  float z0 = enti->points_[6 * 3 + 2] - this->points_[2];
  if (z0 < depth) {
    depth = z0;
    axis.x = 0.f;
    axis.y = 0.f;
    axis.z = z0;
  }
  float z1 = this->points_[6 * 3 + 2] - enti->points_[2];
  if (z1 < depth) {
    depth = z1;
    axis.x = 0.f;
    axis.y = 0.f;
    axis.z = -z1;
  }

  // if ( z0 <= 0 || z1 <= 0 ) {return glm::vec3 (0.f);}
  if (depth <= 0.0) {
    return glm::vec3(0.0f);
  }
  if (axis.x != 0) {
    std::cout << "x";
  }

  return axis;
}

glm::vec4 logic::Entity::GetCenter() {
  return glm::vec4(
      this->points_[18] / 2, this->points_[19] / 2, this->points_[20] / 2,
      1);  // glm::vec4(this->pos.x/2, this->pos.y/2, this->pos.z/2) ;
}

void *logic::Entity::GetPoints() { return this->points_; }

void logic::Entity::MoveForward(float tmp) {  // todo bedenk deftige naam
  for (auto i = 0; i < 8; i++) {
    this->points_[3 * i + 2] += tmp;
  }
}

void logic::Entity::MoveBack(float tmp) {
  for (auto i = 0; i < 8; i++) {
    this->points_[3 * i + 2] -= tmp;
  }
}

void logic::Entity::MoveLeft(float tmp) {
  for (auto i = 0; i < 8; i++) {
    this->points_[3 * i + 0] += tmp;
  }
}

void logic::Entity::MoveRight(float tmp) {
  for (auto i = 0; i < 8; i++) {
    this->points_[3 * i + 0] -= tmp;
  }
}

void logic::Entity::MoveX(float tmp) { MoveRight(tmp); }

void logic::Entity::MoveZ(float tmp) { MoveForward(tmp); }

glm::vec3 logic::Entity::GetPosition() {  // todo kan verkleinen
  glm::vec3 size(points_[6 * 3] - points_[0], points_[6 * 3 + 1] - points_[1],
                 points_[6 * 3 + 2] - points_[2]);

  return glm::vec3(points_[0] + size.x / 2, points_[1] + size.y / 2,
                   points_[2] + size.z / 2);
}

void logic::Entity::SetPosNoX(float y, float z) {}

void logic::Entity::SetPosition(glm::vec3 pos) {
  glm::vec3 size(points_[6 * 3] - points_[0], points_[6 * 3 + 1] - points_[1],
                 points_[6 * 3 + 2] - points_[2]);

  points_[0] = pos.x - size.x / 2;
  points_[1] = pos.y - size.y / 2;
  points_[2] = pos.z - size.z / 2;

  points_[3] = pos.x + size.x / 2;
  points_[4] = pos.y - size.y / 2;
  points_[5] = pos.z - size.z / 2;

  points_[6] = pos.x + size.x / 2;
  points_[7] = pos.y - size.y / 2;
  points_[8] = pos.z + size.z / 2;

  points_[9] = pos.x - size.x / 2;
  points_[10] = pos.y - size.y / 2;
  points_[11] = pos.z + size.z / 2;

  points_[12] = pos.x - size.x / 2;
  points_[13] = pos.y + size.y / 2;
  points_[14] = pos.z - size.z / 2;

  points_[15] = pos.x + size.x / 2;
  points_[16] = pos.y + size.y / 2;
  points_[17] = pos.z - size.z / 2;

  points_[18] = pos.x + size.x / 2;
  points_[19] = pos.y + size.y / 2;
  points_[20] = pos.z + size.z / 2;

  points_[21] = pos.x - size.x / 2;
  points_[22] = pos.y + size.y / 2;
  points_[23] = pos.z + size.z / 2;
}

void logic::Entity::SetPositionBottom(glm::vec3 pos) {
  glm::vec3 size(points_[6 * 3] - points_[0], points_[6 * 3 + 1] - points_[1],
                 points_[6 * 3 + 2] - points_[2]);

  points_[0] = pos.x - size.x / 2;
  points_[1] = pos.y;
  points_[2] = pos.z - size.z / 2;

  points_[3] = pos.x + size.x / 2;
  points_[4] = pos.y;
  points_[5] = pos.z - size.z / 2;

  points_[6] = pos.x + size.x / 2;
  points_[7] = pos.y;
  points_[8] = pos.z + size.z / 2;

  points_[9] = pos.x + size.x / 2;
  points_[10] = pos.y;
  points_[11] = pos.z + size.z / 2;

  points_[12] = pos.x - size.x / 2;
  points_[13] = pos.y + size.y;
  points_[14] = pos.z - size.z / 2;

  points_[15] = pos.x + size.x / 2;
  points_[16] = pos.y + size.y;
  points_[17] = pos.z - size.z / 2;

  points_[18] = pos.x + size.x / 2;
  points_[19] = pos.y + size.y;
  points_[20] = pos.z + size.z / 2;

  points_[21] = pos.x + size.x / 2;
  points_[22] = pos.y + size.y;
  points_[23] = pos.z + size.z / 2;
}

void logic::Entity::Display() {}

glm::vec3 logic::Entity::GetPositionTop() {
  auto pos = GetPosition();
  return glm::vec3(pos.x, points_[6 * 3 + 2], pos.z);
}

logic::Entity::Entity(glm::vec3 pos, glm::vec3 size) {
  points_[0] = pos.x - size.x / 2;
  points_[1] = pos.y - size.y / 2;
  points_[2] = pos.z - size.z / 2;

  points_[3] = pos.x + size.x / 2;
  points_[4] = pos.y - size.y / 2;
  points_[5] = pos.z - size.z / 2;

  points_[6] = pos.x + size.x / 2;
  points_[7] = pos.y - size.y / 2;
  points_[8] = pos.z + size.z / 2;

  points_[9] = pos.x - size.x / 2;
  points_[10] = pos.y - size.y / 2;
  points_[11] = pos.z + size.z / 2;

  points_[12] = pos.x - size.x / 2;
  points_[13] = pos.y + size.y / 2;
  points_[14] = pos.z - size.z / 2;

  points_[15] = pos.x + size.x / 2;
  points_[16] = pos.y + size.y / 2;
  points_[17] = pos.z - size.z / 2;

  points_[18] = pos.x + size.x / 2;
  points_[19] = pos.y + size.y / 2;
  points_[20] = pos.z + size.z / 2;

  points_[21] = pos.x - size.x / 2;
  points_[22] = pos.y + size.y / 2;
  points_[23] = pos.z + size.z / 2;
}

void logic::Entity::SetPosition(glm::vec3 pos, glm::vec3 size) {
  points_[0] = pos.x - size.x / 2;
  points_[1] = pos.y - size.y / 2;
  points_[2] = pos.z - size.z / 2;

  points_[3] = pos.x + size.x / 2;
  points_[4] = pos.y - size.y / 2;
  points_[5] = pos.z - size.z / 2;

  points_[6] = pos.x + size.x / 2;
  points_[7] = pos.y - size.y / 2;
  points_[8] = pos.z + size.z / 2;

  points_[9] = pos.x - size.x / 2;
  points_[10] = pos.y - size.y / 2;
  points_[11] = pos.z + size.z / 2;

  points_[12] = pos.x - size.x / 2;
  points_[13] = pos.y + size.y / 2;
  points_[14] = pos.z - size.z / 2;

  points_[15] = pos.x + size.x / 2;
  points_[16] = pos.y + size.y / 2;
  points_[17] = pos.z - size.z / 2;

  points_[18] = pos.x + size.x / 2;
  points_[19] = pos.y + size.y / 2;
  points_[20] = pos.z + size.z / 2;

  points_[21] = pos.x - size.x / 2;
  points_[22] = pos.y + size.y / 2;
  points_[23] = pos.z + size.z / 2;
}

void logic::Entity::MoveUp(float tmp) {
  for (auto i = 0; i < 8; i++) {
    this->points_[3 * i + 1] += tmp;
  }
}

glm::vec3 logic::Entity::GetSize() {
  return glm::vec3(points_[18] - points_[0], points_[19] - points_[1],
                   points_[20] - points_[2]);
}
