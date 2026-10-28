#pragma once
#include <cstddef>
#include <vector>
#include <iosfwd>
class Matrix{
    public:
    Matrix(std::size_t rows,std::size_t cols);
    std:: size_t rows() const;
    std:: size_t cols() const;
    double& operator()(std::size_t i,std::size_t j);
    const double& operator()(std::size_t i, std::size_t j) const;
    private:
    std::size_t rows_;
    std::size_t cols_;
    std:: vector<double> data_;
};
std::ostream& operator<<(std::ostream& os, const Matrix& m);