//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef TP2_SINWAVEGENERATOR_HPP
#define TP2_SINWAVEGENERATOR_HPP

#include "TimeSeriesGenerator.hpp"

class SinWaveGenerator : public TimeSeriesGenerator {
public:
    SinWaveGenerator(int seed, double A, double w, double phi);
    vector<double> generateTimeSeries(int size) const override;

private:
    double A;
    double w;
    double phi;
};

#endif