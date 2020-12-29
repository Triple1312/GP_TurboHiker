#ifndef GP_SRC_VIEW_DRAWABLE_HPP_
#define GP_SRC_VIEW_DRAWABLE_HPP_

#include <memory>
#include <engine/Renderer.h>
#include <engine/VertexBufferLayout.h>
#include "view/Camera.hpp"

namespace view {

class Drawable {
public:
    std::shared_ptr<VertexArray> vao ;
    std::shared_ptr<IndexBuffer> ibo ;
    std::shared_ptr<VertexBuffer> vbo_v ;
    std::shared_ptr<VertexBuffer> vbo_c ;
    std::shared_ptr<Shader> shader;

    void ChangeColor(void* colors) const;
    void ChangeVertices(void* vertices) const;

    Drawable() = default;

    Drawable(void* verices, unsigned int v_count, void* colors, unsigned int c_count);

    void Draw();


};


} // namespace view



#endif //GP_SRC_VIEW_DRAWABLE_HPP_
