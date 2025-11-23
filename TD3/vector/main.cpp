#include "iostream"
#include "vector" //librairie de vector
#include "algorithm" // librairie des fonctions sur le vector

using namespace std;

int main() {
    // Declaration d'un vector de type int
    vector<int> v1;

    // Declaration et initialisation d'un vector de type double
    vector<double> v2(5, 10.5); // 5 elements de type double
    vector<double> v3 = {1.2,2.1,3.2,4.3};

    // Vector 2D de 4 lignes et 3 colonnes, elements = 0
    vector<vector<int>> v2D(4, vector<int> (2,0));

    // Ajouter un element a la fin
    v1.push_back(10);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    cout << v1[0] << endl;

    // Taille de vector
    int v1_size = v1.size();
    cout << v1.size() << endl;

    // Iteration sur vector
    // Avec des indices
    for (int i = 0; i < v1_size ; ++i) {
        cout << v1[i] << endl;
    }

    // Avec des poinetrus
    for (auto it = v1.begin(); it != v1.end(); it++) {
        cout << *it << endl;
    }

    // Avec de Range-Based boucle for
    for (int value : v1) {
        cout << value << endl;
    }

    // Enlever le dernier element
    v1.pop_back();

    // Ajouter un element sur un indice specifique
    v1.insert(v1.begin()+1,7);

    // Enlever un element sur un indice
    v1.erase(v1.begin()+1);

    // Ordonner les elements
    sort(v1.begin(), v1.end());

    return 0;
}