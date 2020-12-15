cmake_minimum_required(VERSION 3.10)
project(ExprBinaryTree)

add_executable(${PROJECT_NAME} postfix_gen.cpp expr_evaluator.cpp main.cpp)
