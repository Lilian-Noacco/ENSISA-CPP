//
// Created by Lilian Noacco on 12/12/2025.
//

#include "../include/SinWaveGenerator.hpp"
#include <cmath>

SinWaveGenerator::SinWaveGenerator(double a, double f, double p, int s)
    : TimeSeriesGenerator(s), amplitude(a), frequency(f), phase(p)
{
}

SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(0), amplitude(1.0), frequency(1.0), phase(0.0)
{
}

SinWaveGenerator::~SinWaveGenerator()
{
}

vector<double> SinWaveGenerator::generateTimeSeries(int length) const
{
    vector<double> out;
    if (length <= 0) return out;
    out.reserve(length);

    for (int x = 0; x < length; ++x)
    {
        double val = amplitude * sin(frequency * static_cast<double>(x) + phase);
        out.push_back(val);
    }
    return out;
}
