//
// Created by Lilian Noacco on 12/11/2025.
//

#ifndef ENSISA_CPP_TD2_JUMPSEARCH_H
#define ENSISA_CPP_TD2_JUMPSEARCH_H

#include "SearchingAlgorithm.h"
#include <cmath>

class JumpSearch : public SearchingAlgorithm {
public:
    JumpSearch();
    int search(const vector<int>& vec, int target) override;
};

#endif //ENSISA_CPP_TD2_JUMPSEARCH_H
