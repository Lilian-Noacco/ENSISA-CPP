//
// Created by Lilian Noacco on 14/12/2025.
//

#ifndef SIMILARITY_H
#define SIMILARITY_H

#include <vector>

using namespace std;

double euclidean_distance(const vector<double> &x, const vector<double> &y);
double dtw_distance(const vector<double> &x, const vector<double> &y);
double edit_distance_real_sequences(const vector<double> &x, const vector<double> &y);

#endif