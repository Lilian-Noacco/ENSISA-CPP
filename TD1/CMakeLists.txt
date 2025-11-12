cmake_minimum_required(VERSION 4.0)
project(ENSISA_CPP_TD1)

set(CMAKE_CXX_STANDARD 23)

add_executable(ENSISA_CPP main.cpp
        Complex2D.cpp
        Complex2D.h
        my_class.cpp
        my_class.h
        ../TD2/cmake-build-debug/numberComparisons.cpp
        ../TD2/cmake-build-debug/numberComparisons.h)
