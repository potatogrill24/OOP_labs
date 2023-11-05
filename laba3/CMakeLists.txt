cmake_minimum_required(VERSION 3.10)
project(lab3)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SCR src/farray.h src/farray.cpp src/point.h src/point.cpp src/figure.h src/figure.cpp src/triangle.h src/triangle.cpp src/hexagon.h src/hexagon.cpp src/octagon.h src/octagon.cpp)

add_executable(prog main.cpp src/farray.h src/farray.cpp src/point.h src/point.cpp src/figure.h src/figure.cpp src/triangle.h src/triangle.cpp src/hexagon.h src/hexagon.cpp src/octagon.h src/octagon.cpp)

enable_testing()
add_executable(tests tests.cpp src/farray.h src/farray.cpp src/point.h src/point.cpp src/figure.h src/figure.cpp src/triangle.h src/triangle.cpp src/hexagon.h src/hexagon.cpp src/octagon.h src/octagon.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)