cmake_minimum_required(VERSION 3.10)
project(robosim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(OGRE_VERSION 1.12.1)

# add_compile_options(-Wall -Werror -pedantic -Wextra)
add_compile_options(-Wall -Werror -pedantic)

find_package(OGRE ${OGRE_VERSION} REQUIRED COMPONENTS Bites RTShaderSystem)
file(COPY ${OGRE_CONFIG_DIR}/resources.cfg
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(app
               src/application.cpp
               src/application.h
               src/box_node.cpp
               src/box_node.h
               src/creatable_node.cpp
               src/creatable_node.h
               src/entity_factory.cpp
               src/entity_factory.h
               src/entity_type.h
               src/hinge_joint.cpp
               src/hinge_joint.h
               src/main.cpp
               src/scene_builder.cpp
               src/scene_builder.h
               src/sphere_node.cpp
               src/sphere_node.h
               src/types.h
               src/utils.h)
target_link_libraries(app OgreBites OgreRTShaderSystem)

# Subdirectories
add_subdirectory(test)
add_subdirectory(doc)
