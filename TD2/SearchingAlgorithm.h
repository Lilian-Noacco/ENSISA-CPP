//
// Created by Lilian Noacco on 12/11/2025.
//

#ifndef ENSISA_CPP_TD2_SEARCHINGALGORITHM_H
#define ENSISA_CPP_TD2_SEARCHINGALGORITHM_H

#include <vector>

using namespace std;


class SearchingAlgorithm {
public:
    SearchingAlgorithm();
    virtual ~SearchingAlgorithm() = default;
    virtual int search(const vector<int>& , int) = 0;
    int displaySearchResults(ostream& os, int target, int results);

    int static totalComparisons, totalSearch;
    double static averageComparisons; // mean -> double

private:
    int numberComparisons;

};


#endif //ENSISA_CPP_TD2_SEARCHINGALGORITHM_H