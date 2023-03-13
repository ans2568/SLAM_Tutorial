cmake_minimum_required(VERSION 3.0)

project(
    thread
    VERSION 0.1
    DESCRIPTION "thread example"
    LANGUAGES CXX
)

find_package(OpenCV REQUIRED)

add_executable(thread src/mutex.cpp)    # 실행시키고 싶은 cpp 파일로 변경(ex. src/imread.cpp)

target_link_libraries(thread ${OpenCV_LIBS})

target_compile_options(thread PUBLIC -Wall -pthread)