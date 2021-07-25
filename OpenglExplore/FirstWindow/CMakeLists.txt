cmake_minimum_required(VERSION 3.2)

project(FirstWindow)


include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/FirstWindow/3rd-party/freeglut/include)
include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/FirstWindow/3rd-party/glew-2.2.0/include)
include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/FirstWindow/3rd-party/glfw-3.3.4.bin.WIN64/include)
include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/FirstWindow/3rd-party/glm)

include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/FirstWindow/3rd-party/freeglut/lib/x64)
include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/FirstWindow/3rd-party/glew-2.2.0/lib/Release/x64)
include_directories(C:/KhaLe/CodeWars/OOP-Summary/OpenglExplore/FirstWindow/3rd-party/glfw-3.3.4.bin.WIN64/lib-vc2015)

add_executable(FirstWindow FirstWindow.cpp)
target_link_libraries(FirstWindow freeglut glew32 opengl32)