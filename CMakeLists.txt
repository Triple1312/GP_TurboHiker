
project(GP)

cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(dependencies/glew-2.1.0/build/cmake )
include_directories(src dependencies/glew-2.1.0/include)


include( ${CMAKE_CURRENT_LIST_DIR}/dependencies/CmakeLists.txt)

set(view src/view/Entity.cpp src/view/Entity.h
        src/view/Draw.cc src/view/Draw.h
        src/view/EntityFactory.h
        src/view/Obstacle.cpp src/view/Obstacle.h
        src/view/Player.cpp src/view/Player.h
        src/view/Lane.cpp src/view/Lane.h
        src/view/Drawable.hpp
        src/view/World.cpp src/view/World.h
        src/view/Camera.hpp src/view/Drawable.cpp)


#set(controller src/model/MainGame.cc src/model/MainGame.h src/Controller.cpp src/Controller.h)

add_library(model STATIC
        src/model/Entity.cc src/model/Entity.h
        src/model/Player.cpp src/model/Player.h
        src/model/Item.h src/model/Item.cc
        src/model/Scoreboard.cc src/model/Scoreboard.h
        src/model/World.cc src/model/World.h
        src/model/Obstacle.cc src/model/Obstacle.h
        src/model/Menu.cc src/model/Menu.h
        src/model/Lane.cc src/model/Lane.h
        src/model/Widget.cc src/model/Widget.h
        src/model/EntityFactory.hh src/model/PlayerFactory.hh src/model/Clock.hpp)

add_library(engine STATIC
        dependencies/engine/engine/Shader.h dependencies/engine/engine/Shader.cpp
        dependencies/engine/engine/Renderer.h dependencies/engine/engine/Renderer.cpp
        dependencies/engine/engine/VertexBuffer.h dependencies/engine/engine/VertexBuffer.cpp
        dependencies/engine/engine/IndexBuffer.h dependencies/engine/engine/IndexBuffer.cpp
        dependencies/engine/engine/VertexArray.h dependencies/engine/engine/VertexArray.cpp
        dependencies/engine/engine/VertexBufferLayout.h
        )


add_executable( GP main.cpp  ${view} ${controller} src/DisignByContract.h Utils/Random.hpp dependencies/glew-2.1.0/src/glew.c )
add_executable( GP_debug debug.cpp ${view} ${controller} src/DisignByContract.h Utils/Random.hpp dependencies/glew-2.1.0/src/glew.c)
#add_executable(NoUI main.cpp src/Entity.cc src/Entity.h src/Player.cpp src/Player.h src/Item.h src/Item.cc src/Scoreboard.cc src/Scoreboard.h src/World.cc src/World.h src/Obstacle.cc src/Obstacle.h src/MainGame.cc src/MainGame.h src/Menu.cc src/Menu.h src/Lane.cc src/Lane.h src/Widget.cc src/Widget.h src/Vector3.h src/DisignByContract.h)


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(GP sfml-audio sfml-graphics sfml-window sfml-system  -lGL engine model)
target_link_libraries(GP_debug sfml-audio sfml-graphics sfml-window sfml-system  -lGL engine model)