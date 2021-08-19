#ifndef GP_SRC_VIEW_CAMERA_HPP_
#define GP_SRC_VIEW_CAMERA_HPP_
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

class Cam {
  public:
  glm::mat4 view = glm::lookAt(glm::vec3(0, 1.0f, 0), glm::vec3(0, 0.f, -1.f),
                               glm::vec3(0, 1, 0));

  glm::mat4 projection =
      glm::perspective(glm::radians(120.f), 800.f / 600.f, 0.1f, 100.f);


  static Cam* Get() {
    if (!camera) {
      camera = new Cam;
    }
    return camera;
  }

 private:
  static Cam* camera;

  Cam() {
    view = glm::lookAt(glm::vec3(0, 3.0f, -3.0), glm::vec3(0, 0.f, 1.f),
                       glm::vec3(0, 1, 0));

    projection =
        glm::perspective(glm::radians(45.f), 800.f / 600.f, 0.1f, 100.f);
  }
};

#endif  // GP_SRC_VIEW_CAMERA_HPP_
