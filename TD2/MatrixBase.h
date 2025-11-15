//
// Created by Lilian Noacco on 15/11/2025.
//

#ifndef ENSISA_CPP_TD2_MATRIXBASE_H
#define ENSISA_CPP_TD2_MATRIXBASE_H

#include <vector>

class MatrixBase {
protected:
    std::vector<std::vector<double>> data;
    int rows, cols;

public:
    MatrixBase(int r, int c);
    virtual ~MatrixBase() = default;

    void addElement(int row, int col, double value);
    double getElement(int row, int col) const;
    int getRows() const;
    int getCols() const;
    virtual void display() const;

    MatrixBase operator+(const MatrixBase& other) const;
    MatrixBase operator-(const MatrixBase& other) const;
    MatrixBase operator*(const MatrixBase& other) const;
    MatrixBase operator/(const MatrixBase& other) const;

    double getDeterminant() const;
    MatrixBase getInverse() const;
    static MatrixBase getIdentity(int size);
};

#endif //ENSISA_CPP_TD2_MATRIXBASE_H