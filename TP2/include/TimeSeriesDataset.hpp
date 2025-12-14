//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef TP2_TIMESERIESDATASET_HPP
#define TP2_TIMESERIESDATASET_HPP

#include <vector>

using namespace std;

class TimeSeriesDataset {
public:
    TimeSeriesDataset(bool znormalize, bool isTrain);

    void addTimeSeries(const vector<double>& series, int label);
    void addTimeSeries(const vector<double>& series);

    int getNumberOfSamples() const;
    int getMaxLength() const;
    const vector<double>& getData(int index) const;
    int getLabel(int index) const;

private:
    bool znormalize;
    bool isTrain;
    vector<vector<double>> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;

    vector<double> zNormalizeSeries(const vector<double>& series) const;
};

#endif