//
// Created by Phili on 23/11/2020.
//
#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void * data, unsigned int size) : size(size)
{
    GLCall(glGenBuffers(1, &m_RendererID)); // Generate a single buffer
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); // Select the buffer to be drawn
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW)); // Add the data to the buffer

}

VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::ChangeBufferData(const void *data) {
    Bind();
    if (sizeof(&data) == size) {
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

}

