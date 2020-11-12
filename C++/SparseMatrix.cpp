#include <iostream>
using namespace std;
class SparseElement{
    public:
    int i;
    int j;
    int value;
};
class SparseMatrix{
    public :
    int n; 
    int m;
    int num;
    SparseElement * element;

    public:
        void create(SparseElement &ele);
};

void SparseMatrix::create(SparseElement &ele){
    cout<<"Enter number of non-zero elements";
    cin>>ele.value;

}

int main(){
    SparseMatrix matrix();
    cout<<"Enter number of rows";
    cin>>matrix.n;
    cout<<"Enter number of column";
    cin>>matrix.m;

}