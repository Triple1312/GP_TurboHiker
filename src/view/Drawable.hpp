#ifndef GP_SRC_VIEW_DRAWABLE_HPP_
#define GP_SRC_VIEW_DRAWABLE_HPP_

#include <engine/Renderer.h>
#include <engine/VertexBufferLayout.h>

#include <memory>

#include "view/Camera.hpp"

namespace view {

class Drawable {
 public:
  std::shared_ptr<VertexArray> vao;
  std::shared_ptr<IndexBuffer> ibo;
  std::shared_ptr<VertexBuffer> vbo_v;
  std::shared_ptr<VertexBuffer> vbo_c;
  std::shared_ptr<Shader> shader;


  void ChangeColor(void* colors) const;
  void ChangeVertices(void* vertices) const;

  Drawable() = default;

  Drawable(void* verices, unsigned int v_count, void* colors,
           unsigned int c_count);

  void Draw();

  std::string vertex_s =
      "#version 330 core\n"
      "\n"
      "layout(location = 0) in vec3 position;\n"
      "layout(location = 1) in vec3 color;\n"
      "\n"
      "uniform mat4 view;\n"
      "uniform mat4 projection;\n"
      "\n"
      "out vec4 aColor;\n"
      "\n"
      "void main() {\n"
      "    gl_Position = projection * view * vec4(position, 1.0f);\n"
      "    aColor = vec4(color, 1.0f);\n"
      "}";
  std::string fragment_s =
      "#version 330 core\n"
      "\n"
      "out vec4 Fragcolor;\n"
      "in vec4 aColor;\n"
      "\n"
      "void main() {\n"
      "    Fragcolor = aColor;\n"
      "}";

};

}  // namespace view

#endif  // GP_SRC_VIEW_DRAWABLE_HPP_
