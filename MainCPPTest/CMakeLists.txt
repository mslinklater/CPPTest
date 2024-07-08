cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(maincpptest LANGUAGES CXX)

add_compile_options(-std=c++11)

add_executable(cpptest main.cpp lambdas.cpp utils.cpp)