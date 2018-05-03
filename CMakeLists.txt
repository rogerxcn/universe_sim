cmake_minimum_required(VERSION 2.8)
project(OpenGLTest)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        include
)

set(SOURCE_FILES
        main.cpp
        TextureLoader.cpp)



add_executable(OpenGLTest ${SOURCE_FILES})

target_link_libraries(OpenGLTest glu32 freeglut opengl32)
