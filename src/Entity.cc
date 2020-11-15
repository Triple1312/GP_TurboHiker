//
// Created by Phili on 09/11/2020.
//

#include "Entity.h"

void Entity::MoveUp(double offset) {
    pos.y += offset;
}

void Entity::MoveDown(double offset) {
    pos.y -= offset;
}

void Entity::MoveRight(double offset) {
    pos.x += offset;
}

void Entity::MoveLeft(double offset) {
    pos.x -= offset;
}

bool Entity::Collision(std::shared_ptr<Entity> enti) {
    REQUIRE(enti.get() != nullptr, "Tried to find collision with a non-existing Entity");

    ppp::Vec3F l_xyz0 = this->pos ;
    ppp::Vec3F l_xyz1 = this->pos + this->size;

    ppp::Vec3F l_s = this->size;

    ppp::Vec3F r_xyz0 = enti->pos ;
    ppp::Vec3F r_xyz1 = enti->pos + enti->size;
    
    std::cout << "r0 " << r_xyz0.x << " " << r_xyz0.y << " " << r_xyz0.z << std::endl;
    std::cout << "r1 " << r_xyz1.x << " " << r_xyz1.y << " " << r_xyz1.z << std::endl;

    std::cout << "l0 " << l_xyz0.x << " " << l_xyz0.y << " " << l_xyz0.z << std::endl;
    std::cout << "l1 " << l_xyz1.x << " " << l_xyz1.y << " " << l_xyz1.z << std::endl << std::endl;

    if (l_xyz0.x <= r_xyz1.x && r_xyz0.x <= l_xyz1.x) {
        if (l_xyz0.y <= r_xyz1.y && r_xyz0.y <= l_xyz1.y) {
            if (l_xyz0.z <= r_xyz1.z && r_xyz0.z <= l_xyz1.z) {
                std::cout << "ja";
            }
        }
    }




    return (( l_xyz0.x <= r_xyz1.x && r_xyz0.x <= l_xyz1.x) &&
           ( l_xyz0.y <= r_xyz1.y && r_xyz0.y <= l_xyz1.y) &&
           ( l_xyz0.z <= r_xyz1.z && r_xyz0.z <= l_xyz1.z) );
}

entity_type &Entity::GetEntityType() {
    return this->e_t;
}

void Entity::SetEntityType(entity_type type) {
    this->e_t = type;
}

void Entity::SetPosTo(ppp::Vec3F to) {
     this->pos = to;
}

ppp::Vec3F Entity::GetCenter() {
    return this->size/2;//ppp::Vec3F(this->pos.x/2, this->pos.y/2, this->pos.z/2) ;
}

ppp::Vec3F Entity::GetCenterPos() {
    return this->pos + size/2;
}

ppp::Vec3F Entity::GetPos() {
    return this->pos;
}

void Entity::SetCenterPos(ppp::Vec3F p) {
    this->pos = p + GetCenter();
}
