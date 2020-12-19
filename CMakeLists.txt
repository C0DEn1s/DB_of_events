cmake_minimum_required(VERSION 3.17)
project(final)

set(CMAKE_CXX_STANDARD 20)

add_executable(final main.cpp token.h token.cpp condition_parser.h condition_parser.cpp condition_parser_test.cpp test_runner.h date.h date.cpp database.h database.cpp node.h node.cpp)