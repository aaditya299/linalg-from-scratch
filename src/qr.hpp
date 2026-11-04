#pragma once
#include "matrix.hpp"

struct QR{
    Matrix Q;
    Matrix R;
};

QR qr_gram_schmidt(const Matrix& A);