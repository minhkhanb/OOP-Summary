cmake_minimum_required(VERSION 3.2)

project(CoHangXom3D)

add_executable(CoHangXom3D CoHangXom3D.cpp)
target_link_libraries(CoHangXom3D freeglut glew32 opengl32)