//
// Created by Lilian Noacco on 06/11/2025.
//

#include "my_class.h"

my_class::my_class() : element("") {}

my_class::my_class(const string &value) : element(value) {}

void my_class::print_my_element() const {
    cout << element << endl;
}
