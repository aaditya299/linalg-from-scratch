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

Matrix Matrix::operator+(const Matrix& other) const{
    if(rows_!=other.rows_ ||cols_!=other.cols_)
    throw std::invalid_argument("Matrix sizes do not match for+");
    Matrix result(rows_,cols_);
    for(std::size_t k=0;k<data_.size();++k)
    result.data_[k]=data_[k]+other.data_[k];
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const{
    if(cols_ != other.rows_)
    throw std::invalid_argument("matrx sizes do not match for *");
    Matrix result(rows_,other.cols_);
    for(std::size_t i=0;i<rows_;++i)
        for(std::size_t j=0;j<other.cols_;++j){
            double sum=0.0;
            for(std::size_t k=0;k<cols_;++k)
                sum+=data_[i*cols_+k]*other.data_[k*other.cols_+j];
            result.data_[i*result.cols_+j]=sum;
        }
    return result;
}

Matrix Matrix::transpose() const{
    Matrix result(cols_,rows_);
    for(std::size_t i=0;i<rows_;++i)
        for(std::size_t j=0;j<cols_;++j)
            result.data_[j*rows_+i]=data_[i*cols_+j];
    return result;
}