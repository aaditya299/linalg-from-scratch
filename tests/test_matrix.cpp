#include<iostream>
#include "matrix.hpp"
using namespace std;
int main(){
    Matrix A(2,3);
    A(0,0)=1;A(0,1)=2;A(0,2)=3;
    A(1,0)=4;A(1,1)=5;A(1,2)=6;
    cout<<A;
    cout<<A.rows()<<"x"<<A.cols()<<'\n';
    Matrix S = A + A;
    std::cout << S;
    Matrix B(3, 2);
    B(0, 0) = 7;  B(0, 1) = 8;
    B(1, 0) = 9;  B(1, 1) = 10;
    B(2, 0) = 11; B(2, 1) = 12;
    std::cout << A * B;
        std::cout << "A transposed:\n" << A.transpose();
    std::cout << "(A*B)^T:\n" << (A * B).transpose();
    std::cout << "B^T * A^T:\n" << B.transpose() * A.transpose();
}