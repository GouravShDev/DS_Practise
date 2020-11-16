#include <iostream>
using namespace std;

class SparseMatrix{
    int n;
    int m;
    int num;
    int *R;
    int *C;
    int *A;

    public:
        SparseMatrix(int n, int m,int num);
        friend istream & operator>>(istream &is, SparseMatrix &matrix);
        friend ostream & operator<<(ostream &os, SparseMatrix &matrix);

};
SparseMatrix::SparseMatrix(int n , int m,int num){
    this->n = n;
    this->m = m;
    this->num = num;
    R = new int[n+1];
    C = new int[num];
    A = new int[num];
}
istream & operator>>(istream &is, SparseMatrix &matrix){
    int i,index;
    cout<<"Enter non-zero values of matrix\n";
    for(i = 0; i< matrix.n; i++){
        matrix.R[i] = 0;
    }
    for(i = 0; i< matrix.num;i++){
        //cout<<i<<"********\n";
        cin>>index>>matrix.C[i]>>matrix.A[i];
        matrix.R[index]++;
    }
    for(i=1; i < matrix.n; i++){
        matrix.R[i] = matrix.R[i] + matrix.R[i-1];
    }
    return is;
}
ostream & operator<<(ostream &os, SparseMatrix &matrix){
    int i,j,l;
    /*cout<<"Content of R\n";
    for(i=0; i < matrix.n;i++){
        cout<<matrix.R[i]<<" ";
    }
    cout<<endl;
    cout<<"Content of C\n";
    for(i=0; i < matrix.num;i++){
        cout<<matrix.C[i]<<" ";
    }
    cout<<endl;
    cout<<"Content of A\n";
    for(i=0; i < matrix.num;i++){
        cout<<matrix.A[i]<<" ";
    }*/
    for(i=0,l=0; i < matrix.n;i++){
        for(j=0;j<matrix.m;j++){
            if(matrix.R[i] > 0){
                while(l<matrix.R[i]){
                    if(matrix.C[l] == j++){
                        cout<<matrix.A[l++]<<" ";
                    }else{
                        cout<<"0 ";   
                    }   
                }
                if(j<matrix.m){
                    cout<<"0 ";
                    j++;
                }
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }


    return os;

}

int main(){
    SparseMatrix matrix(3,3,4);
    cin>>matrix;
    cout<<endl;
    cout<<matrix;
    return 0;
}