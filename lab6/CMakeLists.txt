# CMake минимальной версии
cmake_minimum_required(VERSION 3.10)

# Название проекта и язык
project(npc_simulator)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установка политики CMake
cmake_policy(SET CMP0135 NEW)

# Включение директорий с заголовочными файлами
include_directories(include)

# Сборка исходных файлов
# Собираем все .cpp файлы из src/ директории, кроме main.cpp
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
list(REMOVE_ITEM SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Создание библиотеки из исходных файлов
add_library(npc_lib ${SRC_FILES})

# Создание основного исполняемого файла и связывание с библиотекой
add_executable(npc_simulator src/main.cpp)
target_link_libraries(npc_simulator npc_lib pthread)

# Включение поддержки тестирования
enable_testing()

# Подключение Google Test через FetchContent
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# Предотвращение переопределения настроек компилятора/линкера родительского проекта
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Загрузка и доступность Google Test
FetchContent_MakeAvailable(googletest)

# Добавление исполняемого файла для тестов
# Здесь мы не включаем main.cpp, только test.cpp и библиотеку
add_executable(npc_tests tests/test.cpp)
target_link_libraries(npc_tests npc_lib gtest gtest_main pthread)

# Автоматическое обнаружение тестов
include(GoogleTest)
gtest_discover_tests(npc_tests)
