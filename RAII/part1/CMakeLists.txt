cmake_minimum_required(VERSION 3.0)

project(
    RAII
    VERSION 0.1
    DESCRIPTION "Design RAII project"
    LANGUAGES CXX
)


add_executable(RAII src/uniqueptr_move.cpp)

target_compile_options(RAII PUBLIC -Wall)