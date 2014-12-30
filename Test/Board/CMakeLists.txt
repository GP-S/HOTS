cmake_minimum_required (VERSION 2.6)

project (HOTS)

file(GLOB_RECURSE HOTS_SRC_FILES ../../Card/* ../../Effect/* ../../Board/* ../../utils/*)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

add_executable(Board_Test ${HOTS_SRC_FILES} Board_Test.cpp)

include_directories(./ ../../Card/ ../../Effect/ ../../Board/ ../../utils/)
