//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef TP2_GAUSSIANGENERATOR_HPP
#define TP2_GAUSSIANGENERATOR_HPP

#include "TimeSeriesGenerator.hpp"

class GaussianGenerator : public TimeSeriesGenerator {
public:
    GaussianGenerator(int seed, double mean, double stdDev);
    vector<double> generateTimeSeries(int size) const override;

private:
    double mean;
    double stdDev;
};

#endif