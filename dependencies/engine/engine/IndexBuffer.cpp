
#include "IndexBuffer.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) // todo make unsigned char if needed
        : m_Count(count)
{
    //ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    glGenBuffers(1, &m_RendererID); // Generate a single buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID); // Select the buffer to be drawn
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW); // Add the data to the buffer
}

IndexBuffer::IndexBuffer() {
    m_Count = 36;
    unsigned int data[] = {
            // Bottom
            3, 2, 0,
            2, 1, 0,

            // Top
            4, 5, 7,
            5, 6, 7,

            // Front
            0, 1, 4,
            1, 5, 4,

            // Back
            6, 2, 3,
            7, 6, 3,

            // Right
            1, 2, 5,
            2, 6, 5,

            // Left
            7, 3, 0,
            4, 7, 0
    };

    glGenBuffers(1, &m_RendererID); // Generate a single buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID); // Select the buffer to be drawn
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(unsigned int), data, GL_STATIC_DRAW); // Add the data to the buffer
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

