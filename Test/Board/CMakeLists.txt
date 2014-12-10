cmake_minimum_required (VERSION 2.6)

project (HOTS)

file(GLOB_RECURSE HOTS_SRC_FILES ../../Board/* ../../utils/*)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

add_executable(Board_Test ${HOTS_SRC_FILES} Board_Test.cpp Card.cpp Card.h)

include_directories(./ ../../Board/)
