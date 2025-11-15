#ifndef MATRIX_NUMERICAL_TPP
#define MATRIX_NUMERICAL_TPP

#include "MatrixNumerical.h"

template <typename T>
MatrixNumerical<T>::MatrixNumerical(int r, int c) : MatrixBase(r, c) {}

template <typename T>
void MatrixNumerical<T>::addElement(int row, int col, T value) {
    MatrixBase::addElement(row, col, static_cast<double>(value));
}

template <typename T>
T MatrixNumerical<T>::getElement(int row, int col) const {
    return static_cast<T>(MatrixBase::getElement(row, col));
}

#endif
