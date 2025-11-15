//
// Created by Lilian Noacco on 12/11/2025.
//

#ifndef ENSISA_CPP_TD2_BINARYSEARCH_H
#define ENSISA_CPP_TD2_BINARYSEARCH_H

#include "SearchingAlgorithm.h"

class BinarySearch : public SearchingAlgorithm {
public:
    BinarySearch();
    int search(const vector<int>& vec, int target) override;
};

#endif //ENSISA_CPP_TD2_BINARYSEARCH_H
