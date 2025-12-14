//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef TP2_STEPGENERATOR_HPP
#define TP2_STEPGENERATOR_HPP

#include "TimeSeriesGenerator.hpp"

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    StepGenerator(int seed);
    vector<double> generateTimeSeries(int size) const override;
};

#endif