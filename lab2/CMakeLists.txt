cmake_minimum_required(VERSION 3.10)
project(oop_lab2)
cmake_policy(SET CMP0135 NEW)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main_lab2 main.cpp)

enable_testing()

add_executable(tests_lab2 tests/test_five.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(tests_lab2 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests_lab2)
