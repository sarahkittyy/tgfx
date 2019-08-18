add_executable(color color.cpp)
target_include_directories(color PUBLIC include/)
target_link_libraries(color tgfx)