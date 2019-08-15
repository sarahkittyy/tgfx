cmake_minimum_required(VERSION 3.13)
project(tgfx)

option(BUILD_TESTS "Build the unit / mock tests" off)
set(COLOR_MODE "true" CACHE STRING "Color support to use for terminal output.")
set_property(CACHE COLOR_MODE PROPERTY STRINGS "true" "256" "16")

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE sources "src/*.cpp")

add_library(tgfx ${sources})
target_include_directories(tgfx PUBLIC "include")
target_compile_options(tgfx PUBLIC -Wall)

if(COLOR_MODE EQUAL "256")
	target_compile_definitions(tgfx PUBLIC COLOR_MODE_256)
elseif(COLOR_MODE EQUAL "16")
	target_compile_definitions(tgfx PUBLIC COLOR_MODE_16)
else()
	target_compile_definitions(tgfx PUBLIC COLOR_MODE_TRUE)
endif()

if(BUILD_TESTS)
	enable_testing()
	add_subdirectory("${CMAKE_SOURCE_DIR}/extern/googletest/googlemock")
	add_subdirectory("test/")
endif()