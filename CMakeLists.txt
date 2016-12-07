cmake_minimum_required(VERSION 3.6)
project(OOP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(OOP1 TASK_1.cpp CAL/calculator.cpp)
add_executable(OOP2 TASK_2.cpp)
add_executable(OOP3 TASK_3.cpp)
add_executable(OOP5 TASK_5.cpp)
add_executable(OOP5_modified TASK_5_modified.cpp)
add_executable(OOP6 TASK_6.cpp)
add_executable(OOP7 TASK_7.cpp)
add_executable(CAL CAL/calculator.cpp CAL/syms.h CAL/syms.cpp CAL/lexer.h CAL/lexer.cpp CAL/error.h CAL/error.cpp CAL/parser.h CAL/parser.cpp)
