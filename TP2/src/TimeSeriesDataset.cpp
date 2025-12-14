//
// Created by Lilian Noacco on 12/12/2025.
//

#include "TimeSeriesDataset.hpp"
#include <cmath>
#include <numeric>

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    addTimeSeries(series);
    labels.push_back(label);
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series) {
    if (series.size() > maxLength) {
        maxLength = series.size();
    }

    if (znormalize) {
        data.push_back(zNormalizeSeries(series));
    } else {
        data.push_back(series);
    }

    numberOfSamples++;
}

vector<double> TimeSeriesDataset::zNormalizeSeries(const vector<double>& series) const {
    double sum = accumulate(series.begin(), series.end(), 0.0);
    double mean = sum / series.size();

    double sq_sum = 0.0;
    for (double val : series) {
        sq_sum += (val - mean) * (val - mean);
    }
    double stdDev = sqrt(sq_sum / series.size());

    vector<double> normalized;
    normalized.reserve(series.size());

    if (stdDev == 0) {
        return series;
    }

    for (double val : series) {
        normalized.push_back((val - mean) / stdDev);
    }
    return normalized;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}

int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}

const vector<double>& TimeSeriesDataset::getData(int index) const {
    return data[index];
}

int TimeSeriesDataset::getLabel(int index) const {
    if (index < labels.size()) {
        return labels[index];
    }
    return -1;
}