//
// Created by Lilian Noacco on 06/11/2025.
//

#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <iostream>
#include <string>

using namespace std;

class my_class {
public:
    my_class();
    my_class(const string &value);
    void print_my_element() const;

private:
    string element;
};

#endif
