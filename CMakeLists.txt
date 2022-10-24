cmake_minimum_required(VERSION 3.0)
project(Sudoku LANGUAGES CXX)

set(TARGET_NAME Sudoku)
set(SUDOKU_MAIN main.cpp)
set(TEST_SOURCES Tests/tests.cpp)
set(TEST_NAME ${TARGET_NAME}_UT)
set(GAME_NAME ${TARGET_NAME}_EXEC)

add_executable(${GAME_NAME} ${SUDOKU_MAIN})

add_executable(${TEST_NAME} ${TEST_SOURCES})

add_compile_options(-Wall -pedantic)
