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
        // Declaring overloading of >> operator
        friend istream & operator>>(istream &is, SparseMatrix &matrix);
        // Declaring overloading of << operator
        friend ostream & operator<<(ostream &os, SparseMatrix &matrix);
        SparseMatrix operator+(SparseMatrix m2);
        // Simple Destructor to release resource
        
        ~SparseMatrix() {delete [] element;} 
};
// Simple Constructor
SparseMatrix::SparseMatrix(int n, int m , int num){
    this->n= n;
    this->m= m;
    this->num=num;
    element = new SparseElement[num+1];
} 

// Definiton for overloading cout<< operator (I_I)
ostream & operator<<(ostream &os, SparseMatrix &matrix){
    cout<<endl;
    int i,j,k; // indices for accessing element array

    for(i=1,k=1; i <=matrix.n;i++){
        for(j=1;j<=matrix.m;j++){
            // Checking if SparseElement contain element for current Index
            if(i== matrix.element[k].i && j== matrix.element[k].j){
                cout<<matrix.element[k++].value<<" ";
                continue;
            }
            // Printing 0 for all other elements
            cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<endl;
    return os;
}
// Definition for overloading cin>> operator
istream & operator>>(istream &is, SparseMatrix &matrix){
    int i;
    for(i=1;i<=matrix.num;i++){
        cin>>matrix.element[i].i>>matrix.element[i].j>>matrix.element[i].value;
    }
    return is;
}

// Overloading + operator for adding matrices
SparseMatrix SparseMatrix::operator+(SparseMatrix m2){
    int i, j ,k;
    // checking if matrix addition is possible
    if(this->n != m2.n || this->m != m2.m) return SparseMatrix(0,0,0);
    
    // Dynamically creating Matrix to store summation    
    SparseMatrix *m3 = new SparseMatrix(n, m, this->num+m2.num);
    i=j=k=1;


    while(i<=num && j<=m2.num){
        if(element[i].i < m2.element[j].i)
            m3->element[k++] = element[i++];
        else if(element[i].i > m2.element[j].i)
            m3->element[k++] = m2.element[j++];
        else{
            if(element[i].j < m2.element[j].j)
                m3->element[k++] = element[i++];
            else if(element[i].j > m2.element[j].j)
                m3->element[k++] = m2.element[j++];
            else{
                m3->element[k] = element[i];
                m3->element[k++].value = element[i++].value + m2.element[j++].value;
            }
        }
    }  
        for(; i <=this->num; i++){
            m3->element[k++] = this->element[i];
        }  
        for(; j <=m2.num; j++){
            m3->element[k++] = m2.element[j];
        }
    m3->num = k;
    // Returning Matrix pointed by m3 pointer
    return *m3;
}

int main(){
    SparseMatrix matrix(3,3,3);
    SparseMatrix matrix2(3,3,2);
    cout<<"Enter non-zero values for 1st Matrix\n";
    cin>>matrix;
    cout<<"Enter non-zero values for 2nd Matrix\n";
    cin>>matrix2;
    // Adding input matrices
    cout<<"First Matrix"<<matrix<<endl;
    cout<<"Second Matrix"<<matrix2<<endl;
    cout<<"Sum Matrix";
    SparseMatrix matrix3 = matrix + matrix2;
    cout<<matrix3;
    
}