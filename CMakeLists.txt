cmake_minimum_required(VERSION 3.10)
project(MAI-OOP-LAB)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

add_library(lab_lib STATIC src/modules.cpp)
add_executable(Main_exe main.cpp)

target_link_libraries(Main_exe lab_lib)

# Добавляем тесты
enable_testing()

add_executable(tests test/test.cpp)
target_link_libraries(tests lab_lib gtest_main)

add_test(NAME Lab01Tests COMMAND tests)