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

    glm::vec4 l_xyz0 = this->pos ;
    glm::vec4 l_xyz1 = this->pos + this->size;

    glm::vec4 l_s = this->size;

    glm::vec4 r_xyz0 = enti->pos ;
    glm::vec4 r_xyz1 = enti->pos + enti->size;
    
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

void Entity::SetPosTo(glm::vec4 to) {
     this->pos = to;
}

glm::vec4 Entity::GetCenter() {
    return glm::vec4(this->size.x/2, this->size.y/2, this->size.z/2, 0);//glm::vec4(this->pos.x/2, this->pos.y/2, this->pos.z/2) ;
}

glm::vec4 Entity::GetCenterPos() {
    return this->pos + GetCenter();
}

glm::vec4 Entity::GetPos() {
    return this->pos;
}

void Entity::SetCenterPos(glm::vec4 p) {
    this->pos = p - GetCenter();
}

std::deque<glm::vec4> Entity::GetAllPoints() {
    std::deque<glm::vec4> result;
    result.push_back(this->pos);
    result.emplace_back(this->pos.x + this->size.x,this->pos.x + this->size.x,this->pos.x + this->size.x,1);
    result.emplace_back(this->pos.x + this->size.x,this->pos.x + this->size.x,this->pos.x + this->size.x,1);
    //todo niet klaar
}

std::deque<glm::vec4> Entity::GetFace(std::uint8_t face_nr) {
    REQUIRE(face_nr < 6 , "asked for an invallid face nr");
    auto p0 = this->pos;
    glm::vec4 p1(this->pos.x, this->pos.y, this->pos.z + this->size.z, 1);
    glm::vec4 p2(this->pos.x + this->size.x, this->pos.y, this->pos.z + this->size.z, 1);
    glm::vec4 p3(this->pos.x + this->size.x, this->pos.y, this->pos.z, 1);
    glm::vec4 p4(this->pos.x, this->pos.y + this->size.y, this->pos.z, 1);
    glm::vec4 p5(this->pos.x, this->pos.y + this->size.y, this->pos.z + this->size.z, 1);
    glm::vec4 p6(this->pos.x + this->size.x, this->pos.y + this->size.y, this->pos.z + this->size.z, 1);
    glm::vec4 p7(this->pos.x + this->size.x, this->pos.y + this->size.y, this->pos.z, 1);

    if ( face_nr == 0 ) {
        return { p0, p1, p2, p3 };
    }
    else if ( face_nr == 1 ) {
        return { p0, p4, p7, p3 };
    }
    else if ( face_nr == 2 ) {
        return { p1, p5, p4, p0 };
    }
    else if ( face_nr == 3 ) {
        return { p2, p6, p5, p1 };
    }
    else if ( face_nr == 4 ) {
        return { p3, p7, p6, p2 };
    }
    else if ( face_nr == 5 ) {
        return { p4, p5, p6, p7 };
    }
    REQUIRE(false, "getting face failed for unknown reason");
    return {};
}


