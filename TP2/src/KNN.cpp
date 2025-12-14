//
// Created by Lilian Noacco on 12/12/2025.
//

#include "KNN.hpp"
#include <cmath>
#include <algorithm>
#include <vector>
#include <limits>
#include <map>

KNN::KNN(int k, string similarity_measure)
    : k(k), similarity_measure(similarity_measure) {}

double KNN::euclidean_distance(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    int len = min(a.size(), b.size());
    for(int i = 0; i < len; ++i) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

double KNN::dtw(const vector<double>& x, const vector<double>& y) {
    int L = x.size();
    int M = y.size();

    vector<vector<double>> D(L + 1, vector<double>(M + 1, numeric_limits<double>::infinity()));

    D[0][0] = 0;

    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= M; ++j) {
            double cost = pow(x[i - 1] - y[j - 1], 2);
            D[i][j] = cost + min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]});
        }
    }

    return sqrt(D[L][M]);
}

double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& ground_truth) {
    int correct = 0;
    int total = testData.getNumberOfSamples();

    for (int i = 0; i < total; ++i) {
        const vector<double>& testSeries = testData.getData(i);
        vector<pair<double, int>> distances;

        for (int j = 0; j < trainData.getNumberOfSamples(); ++j) {
            double dist = 0.0;
            if (similarity_measure == "dtw") {
                dist = dtw(testSeries, trainData.getData(j));
            } else {
                dist = euclidean_distance(testSeries, trainData.getData(j));
            }
            distances.push_back({dist, trainData.getLabel(j)});
        }

        sort(distances.begin(), distances.end());

        map<int, int> classCounts;
        for (int n = 0; n < k && n < distances.size(); ++n) {
            classCounts[distances[n].second]++;
        }

        int predictedClass = -1;
        int maxCount = -1;
        for (auto const& [label, count] : classCounts) {
            if (count > maxCount) {
                maxCount = count;
                predictedClass = label;
            }
        }

        if (predictedClass == ground_truth[i]) {
            correct++;
        }
    }

    return (double)correct / total;
}