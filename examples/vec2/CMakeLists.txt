add_executable(vec2 vec2.cpp)
target_include_directories(vec2 PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(vec2 tgfx)