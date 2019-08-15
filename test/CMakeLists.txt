file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(tgfx_tests test.cpp)
target_include_directories(tgfx_tests PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(tgfx_tests tgfx gtest gmock)

add_test(NAME tgfx_tests COMMAND tgfx_tests)
add_custom_command(
     TARGET tgfx_tests
     COMMENT "Run tests.."
	 POST_BUILD
	 COMMAND tgfx_tests
)