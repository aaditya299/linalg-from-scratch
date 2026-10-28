#include<iostream>
#include "matrix.hpp"
using namespace std;
int main(){
    Matrix A(2,3);
    A(0,0)=1;A(0,1)=2;A(0,2)=3;
    A(1,0)=4;A(1,1)=5;A(1,2)=6;
    cout<<A;
    cout<<A.rows()<<"x"<<A.cols()<<'\n';
}