cmake_minimum_required(VERSION 3.0)

project(
    gtsam_tutorial
    VERSION 0.1
    DESCRIPTION "gtsam library example"
    LANGUAGES CXX
)

find_package(Eigen3 REQUIRED)

find_package(GTSAM REQUIRED)
include_directories(${GTSAM_INCLUDE_DIR})


add_executable(gtsam_tutorial main.cpp)
target_link_libraries(gtsam_tutorial Eigen3::Eigen) 