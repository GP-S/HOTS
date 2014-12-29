cmake_minimum_required (VERSION 2.6)

project (HOTS)

file(GLOB_RECURSE HOTS_SRC_FILES 
				../../IHM/*
				../../Board/*
				../../Card/*
				../../Effect/*
				../../GameEngine/*
				../../utils/*
				../../IA/*
				)


set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

add_executable(GameEngine_Test ${HOTS_SRC_FILES} GameEngine_Test.cpp)

include_directories(
				./
				../../Board/
				../../Card/
				../../Effect/
				../../GameEngine/
				../../IHM/
				../../utils/
				../../IA/
				)
