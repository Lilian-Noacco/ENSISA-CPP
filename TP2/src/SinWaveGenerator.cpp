//
// Created by Lilian Noacco on 12/12/2025.
//

#include "../include/SinWaveGenerator.hpp"
#include <cmath>
#include <cstdlib>

SinWaveGenerator::SinWaveGenerator(int seed, double A, double w, double phi)
    : TimeSeriesGenerator(seed), A(A), w(w), phi(phi) {
}

vector<double> SinWaveGenerator::generateTimeSeries(int size) const {
    vector<double> series;
    series.reserve(size);

    for(int i = 0; i < size; ++i) {
        double value = A * sin(w * i + phi);
        series.push_back(value);
    }
    return series;
}