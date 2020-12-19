

#include "Lane.h"

view::LaneChunk::LaneChunk(glm::vec3 pos, glm::vec3 size) : logic::LaneChunk(pos, size){
    this->ibo = std::make_unique<IndexBuffer>();
    this->vbo_v = std::make_unique<VertexBuffer>(this->points_, 3 * 8 * sizeof(float));

    float colors[] = {
            // bottom
            1.0f, 1.0f, 1.0f, // 0
            1.0f, 0.0f, 0.0f, // 1
            1.0f, 0.0f, 0.0f, // 2
            1.0f, 1.0f, 1.0f, // 3
            // top
            1.0f, 0.0f, 0.0f, // 4
            1.0f, 1.0f, 1.0f, // 5
            1.0f, 0.0f, 0.0f, // 6
            1.0f, 1.0f, 1.0f  // 7
    };

    this->vbo_c = std::make_unique<VertexBuffer>(colors, 3 * 8 * sizeof(float));

    VertexBufferLayout vbl_v;
    VertexBufferLayout vbl_c;
    vbl_v.Push(3);
    vbl_c.Push(3);

    this->vao = std::make_unique<VertexArray>();

    this->vao->AddBuffer(*vbo_v, vbl_v);
    this->vao->AddBuffer(*vbo_c, vbl_c);
    std::string vertex_s = "#version 330 core"
                           "layout(location = 0) in vec3 position;"
                           "layout(location = 1) in vec3 color;"
                           "uniform mat4 view;"
                           "uniform mat4 projection;"
                           "out vec4 aColor;"
                           "void main() {"
                           "    gl_Position = projection * view * vec4(position, 1.0f);"
                           "    aColor = vec4(color, 1.0f);"
                           "}";
    std::string fragment_s = "#version 330 core"
                             "out vec4 Fragcolor;"
                             "in vec4 aColor;"
                             "void main() {"
                             "    Fragcolor = aColor;"
                             "}";
    this->shader = std::make_shared<Shader>("src/view/entity.shader");
}
