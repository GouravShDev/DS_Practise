#include <iostream>
using namespace std;

// Class for Single Element in SparseMatrix
class SparseElement{
    public:
    int i; // Row Number
    int j; // Column Number
    int value; 
};

// Class for Sparse Matrix
class SparseMatrix{
    int n; // Number of rows
    int m; // Number of Column
    int num; // Number of non-zero Elements
    SparseElement * element; // Pointer pointing the Array of SparseElement

    public:
        SparseMatrix(int n, int m , int num); 
        // Method to take Input
        void read();
        // Method to display Matrix output
        void display();
        // Simple Destructor to release resource
        SparseMatrix add(SparseMatrix m1, SparseMatrix m2);
        ~SparseMatrix() {delete [] element;} 
};
// Simple Constructor
SparseMatrix::SparseMatrix(int n, int m , int num){
    this->n= n;
    this->m= m;
    this->num=num;
    element = new SparseElement[num+1];
} 

// Method for diplaying Matrix (I_I)
void SparseMatrix::display(){
    int i,j,k; // indices for accessing element array

    for(i=1,k=1; i <=n;i++){
        for(j=1;j<=m;j++){
            // Checking if SparseElement contain element for current Index
            if(i== element[k].i && j== element[k].j){
                cout<<element[k++].value<<" ";
                continue;
            }
            // Printing 0 for all other elements
            cout<<"0 ";
        }
        cout<<endl;
    }
}
// Method Definition to read input from Console
void SparseMatrix::read(){
    int i;
    for(i=1;i<=num;i++){
        cin>>element[i].i>>element[i].j>>element[i].value;
    }
}
// Method To add two Matrix

SparseMatrix SparseMatrix::add(SparseMatrix m1, SparseMatrix m2){
    SparseMatrix s2(2,1,1);
    if(m1.n != m2.n || m1.m != m2.m) return s2;
    int i, j ,k;
    i=j=1;
    k=1;
    SparseMatrix m3(m1.n, m2.m, m1.num+m2.num);

    while(i<m1.num || j<m2.num){
        if(m1.element[i].i < m2.element[j].i)
            m3.element[k++] = m1.element[i++];
        else if(m1.element[i].i > m2.element[j].i)
            m3.element[k++] = m2.element[j++];
        else if(m1.element[i].j < m2.element[j].j)
            m3.element[k++] = m1.element[i++];
        else if(m1.element[i].j > m2.element[j].j)
            m3.element[k++] = m2.element[j++];
        else{
            m3.element[k] = m1.element[i];
            m3.element[k].value = m1.element[i++].value + m2.element[j++].value;
            k++;
        }
    }  
        for(; i <=m1.num; i++){
            m3.element[k++] = m1.element[i];
        }  
        for(; j <=m2.num; j++){
            m3.element[k++] = m2.element[j];
        }
    
    m3.display();
    return m3;
}

int main(){
    SparseMatrix matrix(3,3,3);
    SparseMatrix matrix2(3,3,2);
    matrix.read();
    cout<<"Enter values for 2nd matrix\n";
    matrix2.read();
    //matrix.display();
    cout<<"*************\n";
    matrix.add(matrix, matrix2);
}