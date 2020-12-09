#ifndef GP_CAMERA_HPP
#define GP_CAMERA_HPP
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>



struct Cam {
    glm::mat4 view = glm::lookAt(glm::vec3(0, 1.0f, 0 ),
                                 glm::vec3(0, 1.f, 5.f ),
                                 glm::vec3(0, 1, 0 ) );

    glm::mat4 projection = glm::perspective(glm::radians(120.f),
                                            800.f/600.f,
                                            0.1f,
                                            100.f );

    static Cam* Get() {
        if (!camera) {
            camera = new Cam;
        }
        return camera;
    }

private:

    static Cam* camera;

    Cam() {
        view = glm::lookAt(glm::vec3(0, 3.0f, -3.0 ),
                           glm::vec3(0, 1.f, 5.f ),
                           glm::vec3(0, 1, 0 ) );

        projection = glm::perspective(glm::radians(45.f),
                                     800.f/600.f,
                                     0.1f,
                                     100.f );
    }
};


#endif //GP_CAMERA_HPP
