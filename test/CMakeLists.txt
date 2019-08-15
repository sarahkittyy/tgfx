file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(test test.cpp)
target_include_directories(test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(test gtest gmock)