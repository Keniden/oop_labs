cmake_minimum_required(VERSION 3.10)
project(oop_lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(figures
    src/FigureArray.cpp
    src/Pentagon.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
)

target_include_directories(figures PUBLIC include)

add_executable(main_lab3 main.cpp)

target_link_libraries(main_lab3 figures)

enable_testing()

add_executable(tests_lab3 tests/test_for_my_figures.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(tests_lab3 figures gtest gtest_main pthread)

include(GoogleTest)
gtest_discover_tests(tests_lab3)
