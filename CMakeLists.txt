cmake_minimum_required(VERSION 3.10)
project(raytracing)

set(CMAKE_CXX_STANDARD 17)

add_executable(raytracing main.cpp)

add_custom_target(run ALL
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/raytracing > image.ppm
    DEPENDS raytracing
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running the program and generating image.ppm"
)
