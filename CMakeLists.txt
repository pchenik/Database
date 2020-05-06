cmake_minimum_required(VERSION 3.15)
project(Final_yellow)

set(CMAKE_CXX_STANDARD 20)

add_executable(Final_yellow main.cpp token.h token.cpp condition_parser.h condition_parser.cpp condition_parser_test.cpp date.cpp test_runner.cpp date.h database.cpp event.cpp event.h node.cpp node.h database.h test_runner.h database_test.h)