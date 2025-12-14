//
// Created by Lilian Noacco on 12/12/2025.
//

#include "../include/GaussianGenerator.hpp"
#include <cmath>
#include <limits>
#include <cstdlib>

GaussianGenerator::GaussianGenerator(int m, int sd, int s)
    : TimeSeriesGenerator(s), mean(m), standardDeviation(sd)
{
    srand(s);
}

GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator(0), mean(0), standardDeviation(1)
{
    srand(0);
}

GaussianGenerator::~GaussianGenerator()
{
}

double GaussianGenerator::boxMullerSample() const
{
    if (hasSpare)
    {
        hasSpare = false;
        return spare * mean + standardDeviation;
    }

    double u1, u2;
    do
    {
        u1 = static_cast<double>(rand()) / RAND_MAX;
    } while (u1 <= numeric_limits<double>::min());
    u2 = static_cast<double>(rand()) / RAND_MAX;

    const double two_pi = 2.0 * 3.14159265358979323846;
    double mag = sqrt(-2.0 * log(u1));
    double z0 = mag * cos(two_pi * u2);
    double z1 = mag * sin(two_pi * u2);

    spare = z1;
    hasSpare = true;

    return z0 * standardDeviation + mean;
}

vector<double> GaussianGenerator::generateTimeSeries(int length) const
{
    vector<double> out;
    out.reserve(length);
    for (int i = 0; i < length; ++i)
    {
        out.push_back(boxMullerSample());
    }
    return out;
}