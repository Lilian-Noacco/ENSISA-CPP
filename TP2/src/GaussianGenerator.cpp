//
// Created by Lilian Noacco on 12/12/2025.
//

#include "GaussianGenerator.hpp"
#include <cmath>
#include <cstdlib>

GaussianGenerator::GaussianGenerator(int seed, double mean, double stdDev)
    : TimeSeriesGenerator(seed), mean(mean), stdDev(stdDev) {
    srand(seed);
}

vector<double> GaussianGenerator::generateTimeSeries(int size) const {
    vector<double> series;
    series.reserve(size);

    for (int i = 0; i < size; ++i) {
        double u1 = (double)rand() / RAND_MAX;
        double u2 = (double)rand() / RAND_MAX;

        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        double value = mean + stdDev * z0;

        series.push_back(value);
    }
    return series;
}