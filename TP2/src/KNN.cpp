//
// Created by Lilian Noacco on 12/12/2025.
//

#include "../include/KNN.hpp"
#include "../include/Similarity.hpp"
#include <algorithm>
#include <map>
#include <stdexcept>

KNN::KNN(int k_val, const string &metric) : k(k_val), similarity_measure(metric)
{
}

KNN::~KNN()
{
}

double KNN::calculateDistance(const vector<double> &a, const vector<double> &b) const
{
    if (similarity_measure == "dtw") return dtw_distance(a, b);
    if (similarity_measure == "edr") return edit_distance_real_sequences(a, b);
    return euclidean_distance(a, b);
}

int KNN::predict(const vector<double> &series,
                 const vector<vector<double>> &trainData,
                 const vector<int> &trainLabels) const
{
    vector<pair<double, int>> distances;
    distances.reserve(trainData.size());

    for (size_t i = 0; i < trainData.size(); ++i)
    {
        distances.push_back({calculateDistance(series, trainData[i]), trainLabels[i]});
    }

    sort(distances.begin(), distances.end(), [](const auto &a, const auto &b) {
        return a.first < b.first;
    });

    map<int, int> counts;
    int limit = min(k, static_cast<int>(distances.size()));
    for (int i = 0; i < limit; ++i)
    {
        counts[distances[i].second]++;
    }

    int bestLabel = -1;
    int maxCount = -1;
    for (const auto &p : counts)
    {
        if (p.second > maxCount)
        {
            maxCount = p.second;
            bestLabel = p.first;
        }
    }
    return bestLabel;
}

double KNN::evaluate(const TimeSeriesDataset &trainData,
                     const TimeSeriesDataset &testData,
                     const vector<int> &groundTruth)
{
    const auto &trainSamples = trainData.getData();
    const auto &trainLabels = trainData.getLabels();
    const auto &testSamples = testData.getData();

    int correct = 0;
    for (size_t i = 0; i < testSamples.size(); ++i)
    {
        int prediction = predict(testSamples[i], trainSamples, trainLabels);
        if (prediction == groundTruth[i])
        {
            correct++;
        }
    }

    return (testSamples.empty()) ? 0.0 : static_cast<double>(correct) / testSamples.size();
}

ostream &KNN::PrintOn(ostream &os) const
{
    os << "KNN Classifier (k=" << k << ", Metric=" << similarity_measure << ")";
    return os;
}

ostream &operator<<(ostream &os, const KNN &knn)
{
    return knn.PrintOn(os);
}