//
// Created by Lilian Noacco on 15/11/2025.
//

#ifndef ENSISA_CPP_TD2_MATRIXNUMERICAL_H
#define ENSISA_CPP_TD2_MATRIXNUMERICAL_H

#include "MatrixBase.h"

template <typename T>
class MatrixNumerical : public MatrixBase {
public:
    MatrixNumerical(int r, int c);
    void addElement(int row, int col, T value);
    T getElement(int row, int col) const;
};

#include "MatrixNumerical.tpp"

#endif //ENSISA_CPP_TD2_MATRIXNUMERICAL_H