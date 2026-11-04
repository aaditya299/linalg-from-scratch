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

vector<double> lu_solve(const LU& f, const vector<double>& b){
    const size_t n=f.L.rows();
    if(b.size()!=n)
        throw invalid_argument("b has the wrong length");
    vector<double> y(n);
    for(size_t i=0;i<n;i++){
        double s=b[f.perm[i]];
        for(size_t j=0;j<i;j++) s-=f.L(i,j)*y[j];
        y[i]=s;
    }
    vector<double> x(n);
    for(size_t  i=n;i-- >0;){
        double s=y[i];
        for(size_t j=i+1;j<n;j++) s-=f.U(i,j)*x[j];
        x[i]=s/f.U(i,i);
    }
    return x;
}

double determinant(const Matrix& A){
    try{
        LU f=lu_decompose(A);
        double d=f.sign;
        for(size_t i=0;i<f.U.rows();i++) d*=f.U(i,i);
        return d;
    } catch (const runtime_error&){
        return 0.0;
    }
}

Matrix inverse(const Matrix& A){
    LU f=lu_decompose(A);
    const size_t n=A.rows();
    Matrix inv(n,n);
    for(size_t j=0;j<n;j++){
        vector<double> e(n,0.0);
        e[j]=1.0;
        vector<double>col=lu_solve(f,e);
        for(size_t i=0;i<n;i++) inv(i,j)= col[i];
    }
    return inv;
}