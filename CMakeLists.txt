cmake_minimum_required(VERSION 3.13)
project(Calc)

set(CMAKE_CXX_STANDARD 11)

set(CALC_SRC_FILES src/Calculator.cpp)

set(TEST_FILES test/CalcBasicCommandTest.cpp)

include_directories(include)

add_executable(Calc ${CALC_SRC_FILES} src/main.cpp)

add_executable(CalcTest ${CALC_SRC_FILES} ${TEST_FILES})

target_include_directories(CalcTest PRIVATE lib/gtest/googletest PRIVATE lib/gtest/googletest/include)

target_link_directories(CalcTest PRIVATE lib/gtest)

target_link_libraries(CalcTest PRIVATE libgtest_main.a PRIVATE libgtest.a)
