//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.hpp"

using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator
{
public:
    SinWaveGenerator(double amplitude, double frequency, double phase, int seed);
    SinWaveGenerator();
    virtual ~SinWaveGenerator();

    virtual vector<double> generateTimeSeries(int length) const override;

private:
    double amplitude;
    double frequency;
    double phase;
};

#endif