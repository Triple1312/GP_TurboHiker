//
// Created by Phili on 23/11/2020.
//

#ifndef IDK_VERTEXARRAY_H
#define IDK_VERTEXARRAY_H

#include "VertexBuffer.h"

class VertexBufferLayout;

class VertexArray {
 private:
  unsigned int m_RendererID = 0;
  unsigned int current_buffer_index = 0;

 public:
  VertexArray();
  ~VertexArray();

  void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

  void Bind() const;
  void Unbind() const;
};

#endif  // IDK_VERTEXARRAY_H
