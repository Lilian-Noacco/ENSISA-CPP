//
// Created by Lilian Noacco on 12/11/2025.
//

#include "BinarySearch.h"

BinarySearch::BinarySearch() : SearchingAlgorithm() {
}

int BinarySearch::search(const vector<int>& vec, int target) {
    numberComparisons = 0;
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        numberComparisons++;
        int mid = left + (right - left) / 2;

        if (vec[mid] == target) {
            return mid;
        }
        if (vec[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
