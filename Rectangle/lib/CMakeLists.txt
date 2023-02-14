add_library(shape STATIC rectangle.cpp)

find_package(OpenCV REQUIRED)

target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(shape ${OpenCV_LIBS})

target_compile_options(shape PRIVATE -Wall)