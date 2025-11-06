//
// Created by Lilian Noacco on 06/11/2025.
//

#include "Complex2D.h"
#include <cmath>

Complex2D::Complex2D() : real(0), imaginary(0) {}

Complex2D::Complex2D(double r, double i) : real(r), imaginary(i) {}

Complex2D::Complex2D(double value) : real(value), imaginary(0) {}

Complex2D::Complex2D(const Complex2D &other) : real(other.real), imaginary(other.imaginary) {}

double Complex2D::getReal() const {
    return real;
}

double Complex2D::getImaginary() const {
    return imaginary;
}

void Complex2D::setReal(double r) {
    real = r;
}

void Complex2D::setImaginary(double i) {
    imaginary = i;
}

Complex2D Complex2D::operator+(const Complex2D &other) const {
    return Complex2D(real + other.real, imaginary + other.imaginary);
}

Complex2D Complex2D::operator-(const Complex2D &other) const {
    return Complex2D(real - other.real, imaginary - other.imaginary);
}

Complex2D Complex2D::operator*(const Complex2D &other) const {
    double r = real * other.real - imaginary * other.imaginary;
    double i = real * other.imaginary + imaginary * other.real;
    return Complex2D(r, i);
}

Complex2D Complex2D::operator/(const Complex2D &other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    double r = (real * other.real + imaginary * other.imaginary) / denominator;
    double i = (imaginary * other.real - real * other.imaginary) / denominator;
    return Complex2D(r, i);
}

bool Complex2D::operator<(const Complex2D &other) const {
    double thisMagnitude = sqrt(real * real + imaginary * imaginary);
    double otherMagnitude = sqrt(other.real * other.real + other.imaginary * other.imaginary);
    return thisMagnitude < otherMagnitude;
}

bool Complex2D::operator>(const Complex2D &other) const {
    double thisMagnitude = sqrt(real * real + imaginary * imaginary);
    double otherMagnitude = sqrt(other.real * other.real + other.imaginary * other.imaginary);
    return thisMagnitude > otherMagnitude;
}

ostream& operator<<(ostream &os, const Complex2D &c) {
    os << c.real << " + " << c.imaginary << "i";
    return os;
}
