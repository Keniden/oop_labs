cmake_minimum_required(VERSION 3.10)
project(oop_lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(figures_lab4
    src/Point.cpp
    src/Pentagon.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
    src/Array.cpp
)

target_include_directories(figures_lab4 PUBLIC include)

add_executable(main_lab4 main.cpp)
target_link_libraries(main_lab4 figures_lab4)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(tests_lab4 tests/test_for_my_figures.cpp)
target_link_libraries(tests_lab4 figures_lab4 gtest gtest_main pthread)

include(GoogleTest)
gtest_discover_tests(tests_lab4)
