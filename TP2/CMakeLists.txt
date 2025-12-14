cmake_minimum_required(VERSION 3.20)
project(TP2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(TP2
        src/main.cpp
        src/TimeSeriesGenerator.cpp
        include/TimeSeriesGenerator.hpp
        src/GaussianGenerator.cpp
        include/GaussianGenerator.hpp
        src/StepGenerator.cpp
        include/StepGenerator.hpp
        src/SinWaveGenerator.cpp
        include/SinWaveGenerator.hpp
        src/TimeSeriesDataset.cpp
        include/TimeSeriesDataset.hpp
        src/KNN.cpp
        include/KNN.hpp
        src/Similarity.cpp
        include/Similarity.hpp)