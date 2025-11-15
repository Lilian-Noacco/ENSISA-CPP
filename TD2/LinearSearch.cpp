//
// Created by Lilian Noacco on 12/11/2025.
//

#include "LinearSearch.h"

LinearSearch::LinearSearch() : SearchingAlgorithm() {
}

int LinearSearch::search(const vector<int>& vec, int target) {
    numberComparisons = 0;

    for (size_t i = 0; i < vec.size(); i++) {
        numberComparisons++;
        if (vec[i] == target) {
            return i;
        }
    }

    return -1;
}
