cmake_minimum_required(VERSION 3.0)

project(
    eigen
    VERSION 0.1
    DESCRIPTION "eigen library example"
    LANGUAGES CXX
)

find_package(Eigen3 REQUIRED)

add_executable(eigen main.cpp)
target_link_libraries(eigen Eigen3::Eigen)