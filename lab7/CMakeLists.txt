cmake_minimum_required(VERSION 3.10)
project(lab_7)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g -O0")

add_executable(lab7
    main.cpp
    ./include/npc.hpp
    ./include/orc.hpp
    ./include/bear.hpp
    ./include/squirrel.hpp
    ./include/factory.hpp
    ./include/fight.hpp
    ./include/observer.h
    ./src/factory.cpp
    ./src/fight.cpp
    ./src/observer.cpp
    ./src/npc.cpp
    ./src/orc.cpp
    ./src/bear.cpp
    ./src/squirrel.cpp
    )

enable_testing()
add_executable(test_lab7
     ./test/test.cpp
    ./include/npc.hpp
    ./include/orc.hpp
    ./include/bear.hpp
    ./include/squirrel.hpp
    ./include/factory.hpp
    ./include/fight.hpp
    ./include/observer.h
    ./src/factory.cpp
    ./src/fight.cpp
    ./src/observer.cpp
    ./src/npc.cpp
    ./src/orc.cpp
    ./src/bear.cpp
    ./src/squirrel.cpp
     )

target_link_libraries(test_lab7 ${GTEST_LIBRARIES})
add_test(NAME counter_test COMMAND test_lab7)
