cmake_minimum_required(VERSION 2.8)

project(app)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# We are using opencv installed from os package manager
# note that the stupid linter may not find the opencv
# headers but it will still compile.

find_package(OpenCV 4.0.0 REQUIRED)

SET(SOURCE_FILES
    src/main.cpp
    src/app.cpp
    src/tile_manager.cpp
    src/edge_detector.cpp
    )


add_executable(app ${SOURCE_FILES})

include_directories(include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(app sfml-graphics sfml-window sfml-system ${OpenCV_LIBS})
