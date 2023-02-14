cmake_minimum_required(VERSION 3.0)

project(
    rectangle
    VERSION 0.1
    DESCRIPTION "include/ lib/ project"
    LANGUAGES CXX
)

add_subdirectory(lib)

add_executable(rectangle main.cpp)

target_link_libraries(rectangle shape)

target_compile_options(rectangle PUBLIC -Wall)