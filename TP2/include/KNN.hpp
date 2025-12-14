//
// Created by Lilian Noacco on 12/12/2025.
//

#ifndef KNN_H
#define KNN_H

#include "TimeSeriesDataset.hpp"
#include <string>
#include <vector>

using namespace std;

class KNN
{
public:
    KNN(int k, const string &metric);
    virtual ~KNN();

    double evaluate(const TimeSeriesDataset &trainData,
                    const TimeSeriesDataset &testData,
                    const vector<int> &groundTruth);

    int predict(const vector<double> &series,
                const vector<vector<double>> &trainData,
                const vector<int> &trainLabels) const;

    virtual ostream &PrintOn(ostream &os) const;
    friend ostream &operator<<(ostream &os, const KNN &knn);

private:
    int k;
    string similarity_measure;

    double calculateDistance(const vector<double> &a, const vector<double> &b) const;
};

#endif