#include "matrix.hpp"
#include <stdexcept>
#include <ostream>
Matrix::Matrix(std::size_t rows,std::size_t cols)
    :rows_(rows),cols_(cols), data_(rows*cols,0.0){}
std::size_t Matrix::rows() const { return rows_;}
std::size_t Matrix::cols() const {return cols_; }

double& Matrix::operator()(std::size_t i,std::size_t j){
    if(i>=rows_ || j>=cols_) throw std::out_of_range("Matrix index out of range");
    return data_[i*cols_+j];
}
const double& Matrix::operator()(std::size_t i,std::size_t j) const {
    if(i>=rows_ || j>=cols_) throw std::out_of_range("Matrix index out of range");
    return data_[i*cols_+j];
}

std::ostream& operator<<(std::ostream& os,const Matrix& m){
    for(std::size_t i=0;i<m.rows();++i){
        for(std::size_t j=0;j<m.cols();++j){
            os<<m(i,j);
            if(j+1<m.cols()) os<<' ';
        }
        os<< '\n';
    }
    return os;
}