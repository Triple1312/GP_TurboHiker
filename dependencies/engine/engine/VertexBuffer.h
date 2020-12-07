//
// Created by Phili on 23/11/2020.
//

#ifndef IDK_VERTEXBUFFER_H
#define IDK_VERTEXBUFFER_H
class VertexBuffer
{
private:
    unsigned int m_RendererID;
    const unsigned int size;
public:
    VertexBuffer(const void* data, unsigned int size);
    VertexBuffer() = default;
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;

    void ChangeBufferData(const void * data);
};




#endif //IDK_VERTEXBUFFER_H
