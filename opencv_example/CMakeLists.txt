cmake_minimum_required(VERSION 3.0)

project(
    opencv
    VERSION 0.1
    DESCRIPTION "OpenCV C++ API example"
    LANGUAGES CXX
)

find_package(OpenCV REQUIRED)

add_executable(opencv src/featureMatching.cpp)    # 실행시키고 싶은 cpp 파일로 변경(ex. src/imread.cpp)

target_link_libraries(opencv ${OpenCV_LIBS})

target_compile_options(opencv PUBLIC -Wall)