cmake_minimum_required(VERSION 3.10)
project(laba01)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab1 laba1.cpp func.cpp)

enable_testing()
add_executable(test1 test001.cpp  func.cpp)
target_link_libraries(test1 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND test001)
