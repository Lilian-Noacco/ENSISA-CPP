//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.hpp"
#include <cstdlib>

using namespace std;

class GaussianGenerator : public TimeSeriesGenerator
{
public:
    GaussianGenerator(int mean, int stdDev, int seed);
    GaussianGenerator();
    virtual ~GaussianGenerator();

    virtual vector<double> generateTimeSeries(int length) const override;

private:
    double boxMullerSample() const;

    int mean;
    int standardDeviation;
    mutable bool hasSpare = false;
    mutable double spare = 0.0;
};

#endif