cmake_minimum_required(VERSION 3.9)
project(OpenGLTest)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        )

add_executable(OpenGLTest ${SOURCE_FILES})

target_link_libraries(OpenGLTest glu32 freeglut opengl32)
