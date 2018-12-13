cmake_minimum_required(VERSION 3.12)
set(EXECUTABLE_NAME "projekt_3D")
add_executable(${EXECUTABLE_NAME} FVIZ_project.cpp
        readData.cpp
        readData.h
        )

# Detect and add SFML
set(SFML_DIR "/usr/share/SFML/cmake/Modules/")
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} stdc++fs)
endif()

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  )

target_link_libraries(projekt_3D ${OPENGL_LIBRARIES})

# c++11
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#message(STATUS "C++11 support has been enabled by default.")
