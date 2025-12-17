//
// Created by Lilian Noacco on 17/12/2025.
//

#ifndef TP_EXAM_KNN_HPP
#define TP_EXAM_KNN_HPP

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class KNN
{
protected:
    int k;
public:
    KNN();
    KNN(int k);

    int getK() const;

    vector<int> findNearestNeighbours(
        vector<T>& trainData,
        T& target
    );

    virtual double similarityMeasure(
        T& a,
        T& b
    ) = 0;
};

#include "../src/KNN.cpp"

#endif //TP_EXAM_KNN_HPP