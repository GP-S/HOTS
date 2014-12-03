cmake_minimum_required (VERSION 2.6)

project (HOTS)

file(GLOB_RECURSE HOTS_SRC_FILES ../../Board/* ./)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

add_executable(HOTS ${HOTS_SRC_FILES})

include_directories(./ ../../Board/)
