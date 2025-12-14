//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.hpp"
#include <cstdlib>

using namespace std;

class StepGenerator : public TimeSeriesGenerator
{
public:
    StepGenerator(int seed);
    StepGenerator();
    virtual ~StepGenerator();

    virtual vector<double> generateTimeSeries(int length) const override;
};

#endif