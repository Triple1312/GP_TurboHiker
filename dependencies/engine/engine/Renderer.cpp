//
// Created by Phili on 23/11/2020.
//

#include "Renderer.h"

#include <iostream>

Renderer* Renderer::instance = 0;

void GLClearError() {
  while (glGetError() != GL_NO_ERROR)
    ;
}

bool GLLogCall(const char* function, const char* file, int line) {
  GLenum error = glGetError();

  if (error) {
    std::cout << "[OpenGL Error] (" << std::hex << error << ") in " << function
              << " at " << file << " on line " << std::dec << line << std::endl;
    return false;
  }

  return true;
}

void Renderer::Clear() const { glClear(GL_COLOR_BUFFER_BIT); }

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib,
                    const Shader& shader) const {
  // Bind everything so we can draw
  shader.Bind();
  va.Bind();
  ib.Bind();

  // Draw the current selected buffer
  glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT,
                 nullptr);  // nullptr, because the indices are bound to the
                            // current buffer: GL_ELEMENT_ARRAY_BUFFER
}