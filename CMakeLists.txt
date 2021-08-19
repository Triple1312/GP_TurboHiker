
project(GP)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_subdirectory(dependencies/engine/engine/freetype2 )
include_directories(src dependencies/glad/include dependencies/engine/engine/freetype2/include)

include( ${CMAKE_CURRENT_LIST_DIR}/dependencies/CmakeLists.txt)
#include( dependencies/engine/engine/freetype-2.10.0/CMakeLists.txt)


set(view
        src/view/Draw.cc src/view/Draw.h
        src/view/Factory.h
        src/view/Obstacle.cpp src/view/Obstacle.h
        src/view/Player.cpp src/view/Player.h
        src/view/Lane.cpp src/view/Lane.h
        src/view/Drawable.hpp
        src/view/Camera.hpp src/view/Drawable.cpp src/view/Scoreboard.cpp src/view/Scoreboard.h src/view/Collectable.cpp src/view/Collectable.h)

add_library(model STATIC
        src/model/Entity.cc src/model/Entity.h
        src/model/Player.cpp src/model/Player.h
        src/model/Scoreboard.cc src/model/Scoreboard.h
        src/model/World.cc src/model/World.h
        src/model/Obstacle.cc src/model/Obstacle.h
        src/model/Lane.cc src/model/Lane.h
        src/model/Factory.h src/model/PlayerFactory.hh
        src/model/Clock.hpp src/model/Trigger.cpp src/model/Trigger.h src/model/GameSettings.cpp src/model/GameSettings.h src/model/Model.cpp src/model/Model.h src/model/Collectable.cpp src/model/Collectable.h)

add_library(engine STATIC
        dependencies/engine/engine/Shader.h dependencies/engine/engine/Shader.cpp
        dependencies/engine/engine/Renderer.h dependencies/engine/engine/Renderer.cpp
        dependencies/engine/engine/VertexBuffer.h dependencies/engine/engine/VertexBuffer.cpp
        dependencies/engine/engine/IndexBuffer.h dependencies/engine/engine/IndexBuffer.cpp
        dependencies/engine/engine/VertexArray.h dependencies/engine/engine/VertexArray.cpp
        dependencies/engine/engine/VertexBufferLayout.h

        dependencies/engine/engine/Texture.cc dependencies/engine/engine/Texture.h dependencies/engine/engine/stb_image.h dependencies/engine/engine/stb_image.cpp)



#include_directories(GP dependencies/engine/engine/freetype-2.10.0/include)
#link_directories(GP dependencies/engine/engine/freetype-2.10.0/build)
add_executable( GP main.cpp  ${view} ${controller} src/DisignByContract.h src/Utils/Random.hpp dependencies/glad/src/glad.c src/Utils/json.hpp src/Utils/gltext.h)
add_executable( GP_debug debug.cpp ${view} ${controller} src/DisignByContract.h src/Utils/Random.hpp dependencies/glad/src/glad.c )
#add_executable(NoUI main.cpp src/Entity.cc src/Entity.h src/Player.cpp src/Player.h src/Item.h src/Item.cc src/Scoreboard.cc src/Scoreboard.h src/World.cc src/World.h src/Obstacle.cc src/Obstacle.h src/MainGame.cc src/MainGame.h src/Menu.cc src/Menu.h src/Lane.cc src/Lane.h src/Widget.cc src/Widget.h src/Vector3.h src/DisignByContract.h)


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

#find_package(Freetype REQUIRED)

target_link_libraries(GP sfml-audio sfml-graphics sfml-window sfml-system -ldl -lGL engine model freetype )
target_link_libraries(GP_debug sfml-audio sfml-graphics sfml-window sfml-system  -ldl -lGL engine model freetype)