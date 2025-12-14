//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef TP2_TIMESERIESGENERATOR_HPP
#define TP2_TIMESERIESGENERATOR_HPP

#include <vector>
#include <iostream>

using namespace std;

class TimeSeriesGenerator {
public:
    int seed;

    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);

    int getSeed() const;
    virtual vector<double> generateTimeSeries(int size) const = 0;
    static void printTimeSeries(const vector<double>& series);
};

#endif