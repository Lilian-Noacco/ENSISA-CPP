//
// Created by Lilian Noacco on 12/11/2025.
//

#include "SearchingAlgorithm.h"
#include <iostream>

using namespace std;

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {
}

int SearchingAlgorithm::displaySearchResults(ostream& os, int target, int results) {
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;

    os << "Recherche de " << target << " : ";
    if (results == -1) {
        os << "Element introuvable" << endl;
    } else {
        os << "Element trouvé à l'indice " << results << endl;
    }
    os << "Nombre de comparaisons : " << numberComparisons << endl;
    os << "Total comparaisons : " << totalComparisons << endl;
    os << "Moyenne comparaisons : " << averageComparisons << endl;

    return results;
}
