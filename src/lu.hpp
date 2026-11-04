#pragma once
#include<cstddef>
#include<vector>
#include "matrix.hpp"

struct LU {
    Matrix L;
    Matrix U;
    std::vector<std::size_t> perm;
    int sign;
};
LU lu_decompose(const Matrix& A);
std::vector<double> lu_solve(const LU& f, const std::vector<double>& b);
double determinant(const Matrix& A);
Matrix inverse(const Matrix& A);