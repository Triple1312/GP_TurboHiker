//
// Created by Phili on 09/11/2020.
//

#include "Entity.h"


collission_type logic::Entity::Collision(std::shared_ptr<Entity> enti) {
    if (( this->points[0] <= enti->points[6*3 + 0] && enti->points[0] <= this->points[6*3 + 0]) &&
          ( this->points[1] <= enti->points[6*3 + 1] && enti->points[1] <= this->points[6*3 + 1]) &&
           ( this->points[2] <= enti->points[6*3 + 2] && enti->points[2] <= this->points[6*3 + 2] )) {

        float x =  enti->points[6*3 + 0] - this->points[0];
        float y = enti->points[6*3 + 1] - this->points[1];
        float z = enti->points[6*3 + 2] - this->points[2];
        if (x <= y && x <= z) {
            return x_col;
        }
        else if ( y <= z && y <= x) {
            return y_col;
        }
        else {
            return z_col;
        }
    }
    return no_col;
}


glm::vec4 logic::Entity::GetCenter() {
    return glm::vec4(this->points[18]/2, this->points[19]/2, this->points[20]/2, 1);//glm::vec4(this->pos.x/2, this->pos.y/2, this->pos.z/2) ;
}


void* logic::Entity::GetPoints()  {
    return this->points;
}

void logic::Entity::MoveForward(float tmp) { // todo bedenk deftige naam
    for (auto i = 0; i < 8; i++) {
        this->points[3 * i + 2] += tmp;
    }
}

void logic::Entity::MoveBack(float tmp ) {
    for (auto i = 0; i < 8; i++) {
        this->points[3 * i + 2] -= tmp;
    }
}

void logic::Entity::MoveLeft(float tmp) {
    for (auto i = 0; i < 8; i++) {
        this->points[3 * i + 0] += tmp;
    }
}

void logic::Entity::MoveRight(float tmp) {
    for (auto i = 0; i < 8; i++) {
        this->points[3 * i + 0] -= tmp;
    }
}

void logic::Entity::MoveX(float tmp) {
    MoveRight(tmp);
}

void logic::Entity::MoveZ(float tmp) {
    MoveForward(tmp);
}

glm::vec3 logic::Entity::GetPosition() { // todo kan verkleinen
    glm::vec3 size(points[6 * 3] - points[0], points[6*3 + 1] - points[1], points[6*3 + 2] - points[2]);

    return glm::vec3(points[0] + size.x, points[1] + size.y, points[2] + size.z);
}

void logic::Entity::SetPosNoX(float y, float z) {

}

void logic::Entity::SetPosition(glm::vec3 pos) {
    glm::vec3 size(points[6 * 3] - points[0], points[6*3 + 1] - points[1], points[6*3 + 2] - points[2]);

    points[0] = pos.x - size.x/2;
    points[1] = pos.y - size.y/2;
    points[2] = pos.z - size.z/2;

    points[3] = pos.x + size.x/2;
    points[4] = pos.y - size.y/2;
    points[5] = pos.z - size.z/2;

    points[6] = pos.x + size.x/2;
    points[7] = pos.y - size.y/2;
    points[8] = pos.z + size.z/2;

    points[9] = pos.x + size.x/2;
    points[10] = pos.y - size.y/2;
    points[11] = pos.z + size.z/2;

    points[12] = pos.x - size.x/2;
    points[13] = pos.y + size.y/2;
    points[14] = pos.z - size.z/2;

    points[15] = pos.x + size.x/2;
    points[16] = pos.y + size.y/2;
    points[17] = pos.z - size.z/2;

    points[18] = pos.x + size.x/2;
    points[19] = pos.y + size.y/2;
    points[20] = pos.z + size.z/2;

    points[21] = pos.x + size.x/2;
    points[22] = pos.y + size.y/2;
    points[23] = pos.z + size.z/2;
}

void logic::Entity::SetPositionBottom(glm::vec3 pos) {
    glm::vec3 size(points[6 * 3] - points[0], points[6*3 + 1] - points[1], points[6*3 + 2] - points[2]);

    points[0] = pos.x - size.x/2;
    points[1] = pos.y ;
    points[2] = pos.z - size.z/2;

    points[3] = pos.x + size.x/2;
    points[4] = pos.y ;
    points[5] = pos.z - size.z/2;

    points[6] = pos.x + size.x/2;
    points[7] = pos.y ;
    points[8] = pos.z + size.z/2;

    points[9] = pos.x + size.x/2;
    points[10] = pos.y ;
    points[11] = pos.z + size.z/2;

    points[12] = pos.x - size.x/2;
    points[13] = pos.y + size.y;
    points[14] = pos.z - size.z/2;

    points[15] = pos.x + size.x/2;
    points[16] = pos.y + size.y;
    points[17] = pos.z - size.z/2;

    points[18] = pos.x + size.x/2;
    points[19] = pos.y + size.y;
    points[20] = pos.z + size.z/2;

    points[21] = pos.x + size.x/2;
    points[22] = pos.y + size.y;
    points[23] = pos.z + size.z/2;
}

void logic::Entity::Display() {

}

glm::vec3 logic::Entity::GetPositionTop() {
    auto pos = GetPosition();
    return glm::vec3 (pos.x, points[6*3 + 2], pos.z);
}

logic::Entity::Entity(glm::vec3 pos, glm::vec3 size) {
    points[0] = pos.x - size.x/2;
    points[1] = pos.y - size.y/2;
    points[2] = pos.z - size.z/2;

    points[3] = pos.x + size.x/2;
    points[4] = pos.y - size.y/2;
    points[5] = pos.z - size.z/2;

    points[6] = pos.x + size.x/2;
    points[7] = pos.y - size.y/2;
    points[8] = pos.z + size.z/2;

    points[9] = pos.x + size.x/2;
    points[10] = pos.y - size.y/2;
    points[11] = pos.z + size.z/2;

    points[12] = pos.x - size.x/2;
    points[13] = pos.y + size.y/2;
    points[14] = pos.z - size.z/2;

    points[15] = pos.x + size.x/2;
    points[16] = pos.y + size.y/2;
    points[17] = pos.z - size.z/2;

    points[18] = pos.x + size.x/2;
    points[19] = pos.y + size.y/2;
    points[20] = pos.z + size.z/2;

    points[21] = pos.x + size.x/2;
    points[22] = pos.y + size.y/2;
    points[23] = pos.z + size.z/2;
}

void logic::Entity::SetPosition(glm::vec3 pos, glm::vec3 size) {
    points[0] = pos.x - size.x/2;
    points[1] = pos.y - size.y/2;
    points[2] = pos.z - size.z/2;

    points[3] = pos.x + size.x/2;
    points[4] = pos.y - size.y/2;
    points[5] = pos.z - size.z/2;

    points[6] = pos.x + size.x/2;
    points[7] = pos.y - size.y/2;
    points[8] = pos.z + size.z/2;

    points[9] = pos.x + size.x/2;
    points[10] = pos.y - size.y/2;
    points[11] = pos.z + size.z/2;

    points[12] = pos.x - size.x/2;
    points[13] = pos.y + size.y/2;
    points[14] = pos.z - size.z/2;

    points[15] = pos.x + size.x/2;
    points[16] = pos.y + size.y/2;
    points[17] = pos.z - size.z/2;

    points[18] = pos.x + size.x/2;
    points[19] = pos.y + size.y/2;
    points[20] = pos.z + size.z/2;

    points[21] = pos.x + size.x/2;
    points[22] = pos.y + size.y/2;
    points[23] = pos.z + size.z/2;
}






