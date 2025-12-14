//
// Created by Lilian Noacco on 12/12/2025.
//

#include "../include/TimeSeriesGenerator.hpp"

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0)
{
}

TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s)
{
}

int TimeSeriesGenerator::getSeed() const
{
    return seed;
}

void TimeSeriesGenerator::printTimeSeries(const vector<double> &series)
{
    for (double val : series)
    {
        cout << val << " ";
    }
    cout << endl;
}