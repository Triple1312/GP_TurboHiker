//
// Created by Phili on 03/12/2020.
//

#include "Obstacle.h"

view::OCube::OCube(glm::vec3 pos)
    : view::Drawable(), logic::OCube(pos, {2, 2, 2}) {
  this->velocity_ = {0, 0, 0};
  this->ibo = std::make_shared<IndexBuffer>();
  this->vbo_v = std::make_shared<VertexBuffer>(&this->points_[0].x,
                                               3 * 8 * sizeof(float));

  float colors[] = {
      0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,

      0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f};

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

void view::OCube::Display() {
  this->ChangeVertices(this->GetPoints());

  this->Draw();
}
view::Horde::Horde(glm::vec3 pos) : view::Drawable(), logic::Horde(pos) {
  this->velocity_ = {0, 0, 0};
  this->ibo = std::make_shared<IndexBuffer>();
  this->vbo_v = std::make_shared<VertexBuffer>(&this->points_[0].x,
                                               3 * 8 * sizeof(float));

  float colors[] = {
      0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,

      0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};

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
void view::Horde::Display() { this->Draw(); }
view::Ramp1::Ramp1(glm::vec3 pos) : logic::Ramp1(pos), view::Drawable() {
  this->velocity_ = {0, 0, 0};
  this->ibo = std::make_shared<IndexBuffer>();
  this->vbo_v = std::make_shared<VertexBuffer>(&this->points_[0].x,
                                               3 * 8 * sizeof(float));

  float colors[] = {
      1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

      0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};

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
void view::Ramp1::Display() { this->Draw(); }
view::Ramp2::Ramp2(glm::vec3 pos) : logic::Ramp2(pos), view::Drawable() {
  this->velocity_ = {0, 0, 0};
  this->ibo = std::make_shared<IndexBuffer>();
  this->vbo_v = std::make_shared<VertexBuffer>(&this->points_[0].x,
                                               3 * 8 * sizeof(float));

  float colors[] = {
      0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,

      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f};

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
void view::Ramp2::Display() { this->Draw(); }
