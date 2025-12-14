//
// Created by Lilian Noacco on 12/12/2025.
//

#include "TimeSeriesGenerator.hpp"

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

TimeSeriesGenerator::TimeSeriesGenerator(int seed) : seed(seed) {}

int TimeSeriesGenerator::getSeed() const {
    return seed;
}

void TimeSeriesGenerator::printTimeSeries(const vector<double>& series) {
    for (const double& value : series) {
        cout << value << " ";
    }
    cout << endl;
}