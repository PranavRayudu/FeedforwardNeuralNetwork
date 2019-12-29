//
// Created by tarak on 12/26/2019.
//

#include <iomanip>
#include "Matrix.h"

// pre: width_ > 0, height_ > 0
Matrix::Matrix(int width_, int height_) {
    w = width_;
    h = height_;

    data = new double *[height_];
    for (int i = 0; i < height_; i++) {
        data[i] = new double[width_](); // making an array of arrays
    }
}

// pre: w of this must equal h of other
Matrix Matrix::operator*(const Matrix &other) {

    Matrix res(this->h, other.w);

    for (int r = 0; r < res.h; r++) {
        for (int c = 0; c < res.w; c++) {

            // take the dot product of this matrix's row at r and other's column at c
            for (int i = 0; i < c; i++) {
                res.data[r][c] += this->data[r][i] * other.data[i][c];
            }
        }
    }

    return res;
}

// pre: w and h of other matrix is same as this one's
Matrix Matrix::operator+(const Matrix &other) {

    Matrix res(this->w, this->h);

    for (int r = 0; r < this->h; r++) {
        for (int c = 0; c < this->w; c++) {
            res.data[r][c] = this->data[r][c] + other.data[r][c];
        }
    }

    return res;
}

void Matrix::set(int r, int c, char v) {
    data[r][c] = v;
}

int Matrix::height() {
    return h;
}

int Matrix::width() {
    return w;
}

ostream &operator<<(ostream &os, const Matrix &other) {

    for (int r = 0; r < other.h; r++) {
        os << '|';
        for (int c = 0; c < other.w; c++) {
            os << std::setw(4) << (int) other.data[r][c];
        }

        os << '|' << endl;
    }

    return os;
}

Matrix::~Matrix() {

    for (int r = 0; r < h; r++) {
        delete[] data[r];
    }

    delete[] data;
    data = nullptr; // do I need this?
}

Matrix::Matrix(const Matrix &other) {
    w = other.w;
    h = other.h;

    this->data = new double *[h];
    for (int r = 0; r < h; r++) {
        data[r] = new double[w];

        for (int c = 0; c < w; c++) {
            this->data[r][c] = other.data[r][c];
        }
    }
}

