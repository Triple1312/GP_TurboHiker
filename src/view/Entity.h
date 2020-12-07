//
// Created by Phili on 27/11/2020.
//

#ifndef GP_ENTITY_V_H
#define GP_ENTITY_V_H

#include <memory>

#include <engine/VertexArray.h>
#include <engine/VertexBuffer.h>
#include <engine/VertexBufferLayout.h>

#include "model/Entity.h"

namespace view {

class Entity {
public:
    explicit Entity();
private:

    std::unique_ptr<VertexArray> vao;
    std::unique_ptr<IndexBuffer> ibo;
    std::unique_ptr<VertexBuffer> vbo;

    //void Update();
};

}



#endif //GP_ENTITY_H
