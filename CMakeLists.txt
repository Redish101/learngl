cmake_minimum_required(VERSION 3.14)

project(learngl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

set(SOURCES 
    src/main.cpp

    src/application.cpp
    src/application.h
)

add_executable(learngl ${SOURCES})

target_link_libraries(learngl PRIVATE
    ${GL_LIBRARIY}
    glfw
    glad
    spdlog
)

add_subdirectory(thirdparty)
