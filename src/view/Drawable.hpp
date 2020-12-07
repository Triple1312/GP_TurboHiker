
#ifndef GP_DRAWABLE_HPP
#define GP_DRAWABLE_HPP

#include <memory>
#include <engine/Renderer.h>
#include <engine/VertexBufferLayout.h>
#include "view/Camera.hpp"

namespace view {

class Drawable {
public:
    int a;
    //std::shared_ptr<VertexArray> vao = nullptr;
//    std::shared_ptr<IndexBuffer> ibo = nullptr;
    VertexBuffer* vbo_v = nullptr;
//    std::shared_ptr<VertexBuffer> vbo_c = nullptr;
    //std::shared_ptr<Shader> shader;

//    void ChangeColor(void* colors) const;
//    void ChangeVertices(void* vertices) const;

    Drawable() = default;

    Drawable(void* verices, unsigned int v_count, void* colors, unsigned int c_count) {  }

    void Draw();


};


} // namespace view



#endif //GP_DRAWABLE_HPP
