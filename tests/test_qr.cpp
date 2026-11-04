#include <algorithm>
#include <cmath>
#include <iostream>
#include "qr.hpp"
using namespace std;

double max_diff(const Matrix& X, const Matrix& Y) {
    double d = 0.0;
    for (size_t i = 0; i < X.rows(); ++i)
        for (size_t j = 0; j < X.cols(); ++j)
            d = max(d, fabs(X(i, j) - Y(i, j)));
    return d;
}

int main() {
    Matrix A(3, 2);
    A(0, 0) = 1; A(0, 1) = 1;
    A(1, 0) = 1; A(1, 1) = 0;
    A(2, 0) = 0; A(2, 1) = 1;
    QR f = qr_gram_schmidt(A);
    cout << "Q:\n" << f.Q << "R:\n" << f.R;
    cout << "max |A - QR|:  " << max_diff(A, f.Q * f.R) << "\n";
    cout << "max |QtQ - I|: "
         << max_diff(f.Q.transpose() * f.Q, Matrix::identity(2)) << "\n";
}