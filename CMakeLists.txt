cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

find_package(OGRE 1.12.1 REQUIRED COMPONENTS Bites RTShaderSystem)
file(COPY ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(app src/main.cpp src/application.cpp src/application.h)
target_link_libraries(app OgreBites OgreRTShaderSystem)
