#include<algorithm>
#include<cmath>
#include<iostream>
#include "lu.hpp"
using namespace std;

int main(){
    Matrix A(3,3);
    A(0,0)=2;A(0,1)=1;A(0,2)=1;
    A(1, 0) = 4; A(1, 1) = 3; A(1, 2) = 3;
    A(2, 0) = 8; A(2, 1) = 7; A(2, 2) = 9;
    LU f=lu_decompose(A);
    cout<<"L\n"<<f.L<<"U:\n"<<f.U<<"perm:";
    for(size_t p :f.perm) cout<<" "<<p;
    cout<<"\n";
    Matrix PA(3,3);
    for(size_t i=0;i<3;i++)
        for(size_t j=0;j<3;j++)
            PA(i,j)=A(f.perm[i],j);
    Matrix prod=f.L*f.U;
    double err=0.0;
    for(size_t i=0;i<3;i++)
        for(size_t j=0;j<3;j++)
            err=max(err,fabs(PA(i,j)-prod(i,j)));
    cout<<"max error: "<<err<<"\n";
}