#include <iostream>
#include "my_class.h"
#include "Complex2D.h"

using namespace std;

string print_function(const string &value) {
    return value;
}

int main() {
    cout << "=== EXERCICE 1: Hello World ===" << endl;

    string hello = "Hello World !";
    cout << "Question 1: " << hello << endl;

    cout << "Question 2: " << print_function("Hello World with function !") << endl;

    my_class obj;
    my_class obj2("Question 4: Hello from my_class !");

    cout << "Question 4 (default constructor): ";
    obj.print_my_element();

    cout << "Question 4 (valued constructor): ";
    obj2.print_my_element();

    cout << "\n=== EXERCICE 2: Nombres Complexes ===" << endl;

    Complex2D c1;
    cout << "c1 (default): " << c1 << endl;

    Complex2D c2(3.0, 4.0);
    cout << "c2 (3, 4): " << c2 << endl;

    Complex2D c3(5.0);
    cout << "c3 (5): " << c3 << endl;

    Complex2D c4(c2);
    cout << "c4 (copy of c2): " << c4 << endl;

    cout << "\nTest des getters:" << endl;
    cout << "c2.getReal() = " << c2.getReal() << endl;
    cout << "c2.getImaginary() = " << c2.getImaginary() << endl;

    cout << "\nTest des setters:" << endl;
    c1.setReal(1.0);
    c1.setImaginary(2.0);
    cout << "c1 after set: " << c1 << endl;

    cout << "\nTest de l'operateur +:" << endl;
    Complex2D sum = c2 + c1;
    cout << c2 << " + " << c1 << " = " << sum << endl;

    cout << "\nTest de l'operateur -:" << endl;
    Complex2D diff = c2 - c1;
    cout << c2 << " - " << c1 << " = " << diff << endl;

    cout << "\nTest de l'operateur *:" << endl;
    Complex2D mult = c2 * c1;
    cout << c2 << " * " << c1 << " = " << mult << endl;

    cout << "\nTest de l'operateur /:" << endl;
    Complex2D div = c2 / c1;
    cout << c2 << " / " << c1 << " = " << div << endl;

    cout << "\nTest des operateurs < et >:" << endl;
    cout << c2 << " < " << c1 << " ? " << (c2 < c1 ? "true" : "false") << endl;
    cout << c2 << " > " << c1 << " ? " << (c2 > c1 ? "true" : "false") << endl;

    return 0;
}
