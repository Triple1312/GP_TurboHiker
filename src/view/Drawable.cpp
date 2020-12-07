#include "view/Drawable.hpp"

//void view::Drawable::ChangeColor(void *colors) const {
//    vbo_c->Bind();
//    glBufferSubData(GL_ARRAY_BUFFER, 0, 3 * 8 * sizeof(float) , colors);
//}
//
//void view::Drawable::ChangeVertices(void *vertices) const {
//    vbo_v->Bind();
//    glBufferSubData(GL_ARRAY_BUFFER, 0, 3 * 8 * sizeof(float) , vertices);
//}

//view::Drawable::Drawable(void* verices, unsigned int v_count, void* colors, unsigned int c_count) {
//    vao = std::make_shared<VertexArray>();
//    ibo = std::make_shared<IndexBuffer>();
//    vbo_v = std::make_shared<VertexBuffer>(verices, v_count);
//    vbo_c = std::make_shared<VertexBuffer>(colors, c_count);
//}

void view::Drawable::Draw() {
//    this->shader->SetUniformMat4f("view", Cam::Get()->view);
//    this->shader->SetUniformMat4f("projection", Cam::Get()->projection);
//    Renderer::Get().Draw(*vao, *ibo, *shader);
}



