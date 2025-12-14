//
// Created by Lilian Noacco on 12/12/2025.
//

#include "../include/TimeSeriesDataset.hpp"
#include <numeric>
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool train)
    : znormalize(znorm), isTrain(train), maxLength(0), numberOfSamples(0)
{
}

TimeSeriesDataset::~TimeSeriesDataset()
{
}

const vector<vector<double>> &TimeSeriesDataset::getData() const { return data; }
const vector<int> &TimeSeriesDataset::getLabels() const { return labels; }

vector<double> TimeSeriesDataset::zNormalize(const vector<double> &series) const
{
    if (series.empty()) return series;

    double sum = accumulate(series.begin(), series.end(), 0.0);
    double mean = sum / series.size();

    double sq_sum = 0.0;
    for (double val : series) sq_sum += (val - mean) * (val - mean);

    double stddev = sqrt(sq_sum / series.size());
    if (stddev < 1e-10) stddev = 1.0;

    vector<double> normalized;
    normalized.reserve(series.size());
    for (double val : series) normalized.push_back((val - mean) / stddev);

    return normalized;
}

void TimeSeriesDataset::addTimeSeries(const vector<double> &series, int label)
{
    vector<double> toAdd = znormalize ? zNormalize(series) : series;
    data.push_back(toAdd);
    labels.push_back(label);

    if (static_cast<int>(toAdd.size()) > maxLength) maxLength = static_cast<int>(toAdd.size());
    numberOfSamples++;
}

void TimeSeriesDataset::addTimeSeries(const vector<double> &series)
{
    addTimeSeries(series, -1);
}

ostream &TimeSeriesDataset::PrintOn(ostream &os) const
{
    os << "Dataset (" << (isTrain ? "Train" : "Test") << ") - Samples: " << numberOfSamples
       << ", MaxLength: " << maxLength << ", Z-Norm: " << (znormalize ? "On" : "Off");
    return os;
}

ostream &operator<<(ostream &os, const TimeSeriesDataset &ds)
{
    return ds.PrintOn(os);
}