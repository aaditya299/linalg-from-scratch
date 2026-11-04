#include "qr.hpp"
#include<cmath>
#include<stdexcept>
#include<vector>
using namespace std;

QR qr_gram_schmidt(const Matrix& A){
    const size_t m=A.rows();
    const size_t n=A.cols();
    if(m<n)
        throw invalid_argument("QR needs rows>=cols");
    Matrix Q(m,n);
    Matrix R(n,n);
    for(size_t j=0;j<n;j++){
        vector<double> v(m);
        for(size_t k=0;k<m;k++){
            v[k]=A(k,j);
        }
        for(size_t i=0;i<j;i++){
            double dot=0.0;
            for(size_t k=0;k<m;k++) dot+=Q(k,i)*A(k,j);
            R(i,j)=dot;
            for(size_t k=0;k<m;k++) v[k]-=dot*Q(k,i);
        }
        double norm=0.0;
        for(size_t k=0;k<m;k++) norm+=v[k]*v[k];
        norm =sqrt(norm);
        if(norm<1e-12)
            throw runtime_error("Columns are linearly dependent");
        R(j,j)=norm;
        for(size_t k=0;k<m;k++)Q(k,j)=v[k]/norm;
    }
    return QR{Q,R};
}