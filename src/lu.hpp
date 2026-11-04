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