//
// Created by Lilian Noacco on 12/11/2025.
//

#ifndef ENSISA_CPP_TD2_LINEARSEARCH_H
#define ENSISA_CPP_TD2_LINEARSEARCH_H

#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm {
public:
    LinearSearch();
    int search(const vector<int>& vec, int target) override;
};

#endif //ENSISA_CPP_TD2_LINEARSEARCH_H
