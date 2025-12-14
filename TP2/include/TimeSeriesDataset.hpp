//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <iostream>

using namespace std;

class TimeSeriesDataset
{
public:
    TimeSeriesDataset(bool znormalize = false, bool isTrain = false);
    virtual ~TimeSeriesDataset();

    void addTimeSeries(const vector<double> &series, int label);
    void addTimeSeries(const vector<double> &series);

    const vector<vector<double>> &getData() const;
    const vector<int> &getLabels() const;

    virtual ostream &PrintOn(ostream &os) const;
    friend ostream &operator<<(ostream &os, const TimeSeriesDataset &dataset);

private:
    vector<double> zNormalize(const vector<double> &series) const;

    bool znormalize;
    bool isTrain;
    vector<vector<double>> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
};

#endif