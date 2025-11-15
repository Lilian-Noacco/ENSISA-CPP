//
// Created by Lilian Noacco on 12/11/2025.
//

#include "JumpSearch.h"

JumpSearch::JumpSearch() : SearchingAlgorithm() {
}

int JumpSearch::search(const vector<int>& vec, int target) {
    numberComparisons = 0;
    int n = vec.size();

    if (n == 0) return -1;

    int step = sqrt(n);
    int prev = 0;
    int next = step;

    while (next < n) {
        numberComparisons++;
        if (vec[next] >= target) {
            break;
        }
        prev = next;
        next += step;
    }

    if (next >= n) {
        next = n - 1;
    }

    for (int i = prev; i <= next; i++) {
        numberComparisons++;
        if (vec[i] == target) {
            return i;
        }
    }

    return -1;
}
