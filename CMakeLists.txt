cmake_minimum_required(VERSION 3.30)
project(Problema_1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Problema_1 main.cpp
        src/myStack.cpp
        include/myStack.h
        include/inputValidation.h
        include/handleProblem1.h
        src/handleProblem1.cpp)
