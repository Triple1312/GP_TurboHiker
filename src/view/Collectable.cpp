//
// Created by phil on 8/16/21.
//

#include "Collectable.h"
void view::Collectable::Display() {
  this->Draw();
}
view::Collectable::Collectable(glm::vec3 pos) : logic::Collectable(pos), view::Drawable(){
  this->velocity_ = {0, 0, 0};
  this->ibo = std::make_shared<IndexBuffer>();
  this->vbo_v = std::make_shared<VertexBuffer>(&this->points_[0].x,
                                               3 * 8 * sizeof(float));

  float colors[] = {
      1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,

      0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};

  this->vbo_c = std::make_shared<VertexBuffer>(colors, 3 * 8 * sizeof(float));

  VertexBufferLayout vbl_v;
  VertexBufferLayout vbl_c;
  vbl_v.Push(3);
  vbl_c.Push(3);

  this->vao = std::make_shared<VertexArray>();

  this->vao->AddBuffer(*vbo_v, vbl_v);
  this->vao->AddBuffer(*vbo_c, vbl_c);
  this->shader = std::make_shared<Shader>(vertex_s, fragment_s);
}
