cmake_minimum_required (VERSION 2.6)

project (HOTS)

file(GLOB_RECURSE HOTS_SRC_FILES 
			IHM/*
			Board/*
			Card/*
			Effect/*
			GameEngine/*
			)

find_package(Threads)
find_package(SDL)
find_package(OpenGL)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

set(HOTS_SCR_DIRS Board/ Card/ Effect/ GameEngine/ IHM/)
set(POLYCODE_INCLUDE_DIRS 
      Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/include 
      Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/include/AL 
      Dependencies/Polycode/Release/Linux/Framework/Core/include 
      Dependencies/Polycode/Release/Linux/Framework/Modules/include 
      Dependencies/Polycode/Release/Linux/Framework/Modules/Dependencies/include 
      Dependencies/Polycode/Release/Linux/Framework/Modules/Dependencies/include/bullet)

set(POLYCODE_LINKER_FLAGS 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Core/lib/libPolycore.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libfreetype.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/lib/liblibvorbisfile.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/lib/liblibvorbis.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/lib/liblibogg.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libopenal.so 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libphysfs.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libpng15.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libz.a
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Modules/lib/libPolycode2DPhysics.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Modules/Dependencies/lib/libBox2D.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Modules/lib/libPolycode3DPhysics.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Modules/lib/libPolycodeUI.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Modules/Dependencies/lib/libBulletDynamics.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Modules/Dependencies/lib/libBulletCollision.a 
      ${PROJECT_SOURCE_DIR}/Dependencies/Polycode/Release/Linux/Framework/Modules/Dependencies/lib/libLinearMath.a)

include_directories(${HOTS_SCR_DIRS} ${POLYCODE_INCLUDE_DIRS})
add_executable(HOTS ${HOTS_SRC_FILES})
target_link_libraries (HOTS ${CMAKE_THREAD_LIBS_INIT} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${SDL_LIBRARY} X11 rt dl ${POLYCODE_LINKER_FLAGS})