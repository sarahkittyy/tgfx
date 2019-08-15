cmake_minimum_required(VERSION 3.13)
project(tgfx)

option(BUILD_TESTS "Build the unit / mock tests" off)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE sources "src/*.cpp")

if(BUILD_TESTS)
	add_subdirectory("${CMAKE_SOURCE_DIR}/extern/googletest/googlemock")
	add_subdirectory("test/")
endif()

add_library(tgfx ${sources})
target_include_directories(tgfx PUBLIC "include")
target_compile_options(tgfx PUBLIC -Wall)