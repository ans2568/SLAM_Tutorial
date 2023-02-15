cmake_minimum_required(VERSION 3.0)

add_library(date date.cpp)

target_include_directories(date PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_options(date PRIVATE -Wall)