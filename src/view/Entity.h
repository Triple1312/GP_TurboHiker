//
// Created by Phili on 27/11/2020.
//

#ifndef GP_SRC_VIEW_ENTITY_H_
#define GP_SRC_VIEW_ENTITY_H_

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

    std::unique_ptr<VertexArray> vao_;
    std::unique_ptr<IndexBuffer> ibo_;
    std::unique_ptr<VertexBuffer> vbo_;

    //void Update();
};

}



#endif //GP_SRC_MODEL_ENTITY_H_
