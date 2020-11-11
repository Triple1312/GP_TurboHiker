
project(GP)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

if(APPLE)
    set(SFML_INCLUDE_DIR "libs/SFML-2.5.1-MAC/include")
    set( SFML_LIBRARY_DIR "libs/SFML-2.5.1-MAC/build/lib")

elseif (UNIX)
    set(SFML_INCLUDE_DIR "libs/SFML-2.5.1/include/")
    set(SFML_LIBRARY_DIR "libs/SFML-2.5.1/lib/")
    set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML/")
    set(SFML_SHARE "libs/SFML-2.5.1/share/")

elseif(WIN32)
    set(SFML_INCLUDE_DIR "libs/SFML-2.5.1_WIN/include/")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/SFML-2.5.1_WIN/lib/cmake/SFML")
    set(SFML_LIBRARY_DIR "libs/SFML-2.5.1_WIN/lib/")
    file(GLOB SFML_DLL "libs/SFML-2.5.1_WIN/bin/*.dll")
    file(COPY ${SFML_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

endif()

link_directories(SFML_LIBRARY_DIR )
include_directories(SFML_INCLUDE_DIR )

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)


if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

file(GLOB_RECURSE SCRF "src/*.cpp" "src/*.hpp")

add_executable( GP main.cpp src/Entity.cc src/Entity.h src/Player.cpp src/Player.h src/Item.h src/Item.cc src/Scoreboard.cc src/Scoreboard.h)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(GP sfml-audio sfml-graphics sfml-window sfml-system )