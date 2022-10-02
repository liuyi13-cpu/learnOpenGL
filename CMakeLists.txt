cmake_minimum_required(VERSION 3.19)
project(learnOpenGL)

set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/local/Cellar/glew/2.2.0_1/include/GL)
include_directories(/usr/local/Cellar/glfw/3.3.8/include/GLFW)
include_directories(glad/include)

link_libraries(${OPENGL})
link_libraries(/usr/local/Cellar/glfw/3.3.8/lib/libglfw.3.dylib)
link_libraries(/usr/local/Cellar/glfw/3.3.8/lib/libglfw.3.dylib)

add_executable(learnOpenGL main.cpp glad/src/glad.c test1.cpp test1.h)

# mac下这步很重要
if (APPLE)
    target_link_libraries(learnOpenGL "-framework OpenGL")
    target_link_libraries(learnOpenGL "-framework GLUT")
endif()