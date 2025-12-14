//
// Created by Lilian Noacco on 12/12/2025.
//

#include "StepGenerator.hpp"
#include <cstdlib>

StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {
    srand(seed);
}

vector<double> StepGenerator::generateTimeSeries(int size) const {
    vector<double> series;
    series.reserve(size);
    double currentValue = 0;
    series.push_back(currentValue);

    for(int i = 1; i < size; ++i) {
        if(rand() % 2 == 0) {
            currentValue = rand() % 101;
        }
        series.push_back(currentValue);
    }
    return series;
}