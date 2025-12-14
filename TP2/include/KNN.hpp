//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef TP2_KNN_HPP
#define TP2_KNN_HPP

#include "TimeSeriesDataset.hpp"
#include <string>

using namespace std;

class KNN {
public:
    KNN(int k, string similarity_measure);
    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& ground_truth);

private:
    int k;
    string similarity_measure;

    double euclidean_distance(const vector<double>& a, const vector<double>& b);
    double dtw(const vector<double>& a, const vector<double>& b);
};

#endif