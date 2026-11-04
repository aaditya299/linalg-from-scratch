#include "lu.hpp"
#include <cmath>
#include <stdexcept>
#include <utility>
using namespace std;
LU lu_decompose(const Matrix& A){
    if (A.rows()!=A.cols())
        throw invalid_argument("LU needs a square matrix");
    const size_t n=A.rows();
    Matrix U=A;
    Matrix L=Matrix::identity(n);
    vector<size_t> perm(n);
    for(size_t i=0;i<n;++i) perm[i]=i;
    int sign =1;
    for(size_t k=0;k<n;++k){
        size_t p=k;
        for(size_t i=k+1;i<n;++i)
            if(fabs(U(i,k))>fabs(U(p,k))) p=i;
        if(fabs(U(p,k))<1e-12)
            throw runtime_error("Matrix is singular");
        if(p!=k){
            for(size_t j=0;j<n;++j) swap(U(k,j),U(p,j));
            for(size_t j=0;j<k;++j) swap(L(k,j),L(p,j));
            swap(perm[k],perm[p]);
            sign=-sign;
        }
        for(size_t i=k+1;i<n;++i){
            const double factor=U(i,k)/U(k,k);
            L(i,k)=factor;
            U(i,k)=0.0;
            for(size_t j=k+1;j<n;++j)
                U(i,j)-=factor*U(k,j);
        }
    }
    return LU{L,U,perm,sign};
}