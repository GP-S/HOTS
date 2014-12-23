cmake_minimum_required (VERSION 2.6)

project (HOTS)

file(GLOB_RECURSE HOTS_SRC_FILES Board/* Card/* Effect/* GameEngine/* IHM/*)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

add_executable(HOTS ${HOTS_SRC_FILES})