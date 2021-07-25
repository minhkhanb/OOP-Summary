cmake_minimum_required(VERSION 3.2)

project(EvalTest)

include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/EvalTest/3rd-party/freeglut/include)
include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/EvalTest/3rd-party/glew-2.2.0/include)

include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/EvalTest/3rd-party/freeglut/lib/x64)
include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/EvalTest/3rd-party/glew-2.2.0/lib/Release/x64)

add_executable(EvalTest EvalTest.cpp)
target_link_libraries(EvalTest freeglut glew32 opengl32)