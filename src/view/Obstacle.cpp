//
// Created by Phili on 03/12/2020.
//

#include "Obstacle.h"

view::Obstacle::Obstacle() {
    //this->ibo = std::make_unique<IndexBuffer>();
    //this->vbo_v = std::make_unique<VertexBuffer>(this->points, 3 * 8 * sizeof(float));

    float colors[] = {
            // bottom
            1.0f, 1.0f, 1.0f,// 0
            1.0f, 0.0f, 0.0f,// 1
            1.0f, 0.0f, 0.0f,// 2
            1.0f, 1.0f, 1.0f,// 3
            // top
            1.0f, 0.0f, 0.0f,// 4
            1.0f, 1.0f, 1.0f,// 5
            1.0f, 0.0f, 0.0f,// 6
            1.0f, 1.0f, 1.0f // 7
    };

    //this->vbo_c = std::make_unique<VertexBuffer>(colors, 3 * 8 * sizeof(float));

    VertexBufferLayout vbl_v;
    VertexBufferLayout vbl_c;
    vbl_v.Push(3);
    vbl_c.Push(3);

    //this->vao = std::make_unique<VertexArray>();

    //this->vao->AddBuffer(*vbo_v, vbl_v);
    //this->vao->AddBuffer(*vbo_c, vbl_c);
}
