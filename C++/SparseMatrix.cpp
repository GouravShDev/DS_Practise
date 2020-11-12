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
        ~SparseMatrix(){
            delete []element;
        
        }
};
// Simple Constructor
SparseMatrix::SparseMatrix(int n, int m , int num){
    this->n= n;
    this->m= m;
    this->num=num;
    element = new SparseElement[num];
} 

// Method for diplaying Matrix (I_I)
void SparseMatrix::display(){
    int i,j,k; // indices for accessing element array

    for(i=0,k=0; i < m;i++){
        for(j=0;j<n;j++){
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
    for(i=0;i<num;i++){
        cin>>element[i].i>>element[i].j>>element[i].value;
    }
}


int main(){
    int n,m,num;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of column: ";
    cin>>m;
    cout<<"Enter number of Non-zero Elements: ";
    cin>>num;
    SparseMatrix matrix(n,m,num);
    matrix.read();
    matrix.display();

}