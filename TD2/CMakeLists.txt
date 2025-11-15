cmake_minimum_required(VERSION 4.0)
project(ENSISA_CPP_TD2)

set(CMAKE_CXX_STANDARD 23)

add_executable(ENSISA_CPP main.cpp
        SearchingAlgorithm.cpp
        SearchingAlgorithm.h
        LinearSearch.cpp
        LinearSearch.h
        JumpSearch.cpp
        JumpSearch.h
        BinarySearch.cpp
        BinarySearch.h
        MatrixBase.cpp
        MatrixBase.h
        MatrixNumerical.cpp
        MatrixNumerical.h
)
