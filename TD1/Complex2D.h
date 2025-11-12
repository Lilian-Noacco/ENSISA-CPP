//
// Created by Lilian Noacco on 06/11/2025.
//

#ifndef COMPLEX2D_H
#define COMPLEX2D_H

#include <iostream>

using namespace std;

class Complex2D {
public:
    Complex2D();
    Complex2D(double r, double i);
    Complex2D(double value);
    Complex2D(const Complex2D &other);

    double getReal() const;
    double getImaginary() const;
    void setReal(double r);
    void setImaginary(double i);

    Complex2D operator+(const Complex2D &other) const;
    Complex2D operator-(const Complex2D &other) const;
    Complex2D operator*(const Complex2D &other) const;
    Complex2D operator/(const Complex2D &other) const;
    bool operator<(const Complex2D &other) const;
    bool operator>(const Complex2D &other) const;

    friend ostream& operator<<(ostream &os, const Complex2D &c);

private:
    double real;
    double imaginary;
};

#endif
