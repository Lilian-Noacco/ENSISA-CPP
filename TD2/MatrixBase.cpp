//
// Created by Lilian Noacco on 15/11/2025.
//

#include "MatrixBase.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

MatrixBase::MatrixBase(int r, int c) : rows(r), cols(c) {
    data.assign(r, std::vector<double>(c, 0.0));
}

void MatrixBase::addElement(int row, int col, double value) {
    if (row >= rows || col >= cols || row < 0 || col < 0) {
        throw std::out_of_range("Index out of bounds");
    }
    data[row][col] = value;
}

double MatrixBase::getElement(int row, int col) const {
    if (row >= rows || col >= cols || row < 0 || col < 0) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[row][col];
}

int MatrixBase::getRows() const {
    return rows;
}

int MatrixBase::getCols() const {
    return cols;
}

void MatrixBase::display() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

MatrixBase MatrixBase::operator+(const MatrixBase& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    MatrixBase result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

MatrixBase MatrixBase::operator-(const MatrixBase& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    MatrixBase result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

MatrixBase MatrixBase::operator*(const MatrixBase& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication");
    }
    MatrixBase result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

MatrixBase MatrixBase::operator/(const MatrixBase& other) const {
    return *this * other.getInverse();
}

double MatrixBase::getDeterminant() const {
    if (rows != cols) {
        throw std::invalid_argument("Determinant requires a square matrix");
    }

    if (rows == 1) return data[0][0];
    if (rows == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];

    double det = 0.0;
    for (int j = 0; j < cols; j++) {
        MatrixBase minor(rows - 1, cols - 1);
        for (int i = 1; i < rows; i++) {
            int minorCol = 0;
            for (int k = 0; k < cols; k++) {
                if (k != j) {
                    minor.data[i - 1][minorCol++] = data[i][k];
                }
            }
        }
        double sign = (j % 2 == 0) ? 1.0 : -1.0;
        det += sign * data[0][j] * minor.getDeterminant();
    }
    return det;
}

MatrixBase MatrixBase::getInverse() const {
    if (rows != cols) {
        throw std::invalid_argument("Inverse requires a square matrix");
    }

    double det = getDeterminant();
    if (std::abs(det) < 1e-10) {
        throw std::invalid_argument("Matrix is singular, cannot be inverted");
    }

    if (rows == 1) {
        MatrixBase inv(1, 1);
        inv.data[0][0] = 1.0 / data[0][0];
        return inv;
    }

    if (rows == 2) {
        MatrixBase inv(2, 2);
        inv.data[0][0] = data[1][1] / det;
        inv.data[0][1] = -data[0][1] / det;
        inv.data[1][0] = -data[1][0] / det;
        inv.data[1][1] = data[0][0] / det;
        return inv;
    }

    MatrixBase adj(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            MatrixBase minor(rows - 1, cols - 1);
            int minorRow = 0;
            for (int r = 0; r < rows; r++) {
                if (r != i) {
                    int minorCol = 0;
                    for (int c = 0; c < cols; c++) {
                        if (c != j) {
                            minor.data[minorRow][minorCol++] = data[r][c];
                        }
                    }
                    minorRow++;
                }
            }
            double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
            adj.data[j][i] = sign * minor.getDeterminant();
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            adj.data[i][j] /= det;
        }
    }

    return adj;
}

MatrixBase MatrixBase::getIdentity(int size) {
    MatrixBase identity(size, size);
    for (int i = 0; i < size; i++) {
        identity.data[i][i] = 1.0;
    }
    return identity;
}
