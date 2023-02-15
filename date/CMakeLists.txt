cmake_minimum_required(VERSION 3.0)

project(
    main
    VERSION 0.1
    DESCRIPTION "class capsulation"
    LANGUAGES CXX
)

add_subdirectory(lib)

add_executable(main main.cpp)

target_link_libraries(main date)