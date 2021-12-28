cmake_minimum_required(VERSION 2.8)

project(app)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
SET(SOURCE_FILES
    src/main.cpp
    src/app.cpp
    src/tile_manager.cpp
    )


add_executable(app ${SOURCE_FILES})

include_directories( include )
target_link_libraries(app sfml-graphics sfml-window sfml-system)
