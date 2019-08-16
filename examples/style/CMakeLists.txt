add_executable(style style.cpp)
target_link_libraries(style tgfx)
target_include_directories(style PUBLIC "${CMAKE_SOURCE_DIR}/include")