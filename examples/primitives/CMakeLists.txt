add_executable(primitives primitives.cpp)
target_include_directories(primitives PUBLIC include/)
target_link_libraries(primitives tgfx)