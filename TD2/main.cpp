#include <iostream>
#include <vector>
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"
#include "MatrixNumerical.h"

using namespace std;

int main() {
    cout << "\n=== EXERCICE 1: Algorithmes de recherche ===\n" << endl;
    vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    LinearSearch linear;
    JumpSearch jump;
    BinarySearch binary;

    cout << "=== Recherche Linéaire ===" << endl;
    int result = linear.search(vec, 7);
    linear.displaySearchResults(cout, 7, result);

    cout << "\n=== Recherche par Saut ===" << endl;
    result = jump.search(vec, 7);
    jump.displaySearchResults(cout, 7, result);

    cout << "\n=== Recherche Binaire ===" << endl;
    result = binary.search(vec, 7);
    binary.displaySearchResults(cout, 7, result);

    cout << "\n=== Résultats Finaux ===" << endl;
    cout << "Total des comparaisons : " << SearchingAlgorithm::totalComparisons << endl;
    cout << "Nombre total de recherches : " << SearchingAlgorithm::totalSearch << endl;
    cout << "Moyenne des comparaisons : " << SearchingAlgorithm::averageComparisons << endl;

    cout << "\n=== EXERCICE 2: Matrices ===\n" << endl;

    MatrixNumerical<int> m1(2, 2);
    m1.addElement(0, 0, 1);
    m1.addElement(0, 1, 2);
    m1.addElement(1, 0, 3);
    m1.addElement(1, 1, 4);

    cout << "Matrice m1:" << endl;
    m1.display();

    MatrixNumerical<double> m2(2, 2);
    m2.addElement(0, 0, 2.0);
    m2.addElement(0, 1, 3.0);
    m2.addElement(1, 0, 1.0);
    m2.addElement(1, 1, 4.0);

    cout << "\nMatrice m2:" << endl;
    m2.display();

    return 0;
}
