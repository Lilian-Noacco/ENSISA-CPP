//
// Created by Lilian Noacco on 12/12/2025.
//

#include "../include/StepGenerator.hpp"
#include <cstdlib>

StepGenerator::StepGenerator(int s)
    : TimeSeriesGenerator(s)
{
    srand(s);
}

StepGenerator::StepGenerator()
    : TimeSeriesGenerator(0)
{
    srand(0);
}

StepGenerator::~StepGenerator()
{
}

vector<double> StepGenerator::generateTimeSeries(int length) const
{
    vector<double> out;
    if (length <= 0) return out;
    out.reserve(length);

    double prev = 0;
    out.push_back(prev);

    for (int i = 1; i < length; ++i)
    {
        if (rand() % 2 == 0)
        {
            out.push_back(prev);
        }
        else
        {
            prev = static_cast<double>(rand() % 101);
            out.push_back(prev);
        }
    }
    return out;
}
