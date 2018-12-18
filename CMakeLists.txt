cmake_minimum_required(VERSION 2.6)

project(jeux)
include_directories("src/" ${CMAKE_CURRENT_BINARY_DIR})

file(
GLOB_RECURSE
source_files
src/*.[cht]pp
src/*.h
)

add_executable(jeux ${source_files})

SET(CMAKE_BUILD_TYPE Debug)
ADD_DEFINITIONS( -O2 -Wall -Wextra -std=c++11 -Wno-comment -Wno-unused-parameter -Wno-unused-function -DCORRECTION -I/usr/include/irrlicht)

TARGET_LINK_LIBRARIES(jeux -lIrrlicht)
