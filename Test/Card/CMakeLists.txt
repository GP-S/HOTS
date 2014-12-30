cmake_minimum_required (VERSION 2.6)

project (HOTS)

file(GLOB_RECURSE HOTS_SRC_FILES ../../Card/* ../../Effect/*)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

add_executable(Card_Test ${HOTS_SRC_FILES} Card_Test.cpp ../../utils/tool.inc)

include_directories(./ ../../Card/ ../../Effect/ ../../utils/)
