cmake_minimum_required(VERSION 3.10)
project(robosim)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

find_package(OGRE 1.12.1 REQUIRED COMPONENTS Bites RTShaderSystem)
file(COPY ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(app src/main.cpp
        src/application.cpp src/application.h
        src/box.cpp src/box.h
        src/sphere_creator.cpp src/sphere_creator.h src/scene_manager.cpp src/scene_manager.h)
target_link_libraries(app OgreBites OgreRTShaderSystem)

# Subdirectories
add_subdirectory(test)
