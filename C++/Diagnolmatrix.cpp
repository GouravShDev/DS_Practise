#include <iostream>
using namespace std;
class DiagonalMatrix{
    private:
        int *A;
        int n;
    public:
        DiagonalMatrix(){
            n = 5;
            A = new int[5];
        }
        DiagonalMatrix(int n){
            this->n = n;
            A = new int[n];

        }
        void set(int i , int j, int value){
            if(i==j){
                A[i] = value;
            }
        }
        int get(int i , int j){
            if(i!=j) return 0;  
            return A[i];
        }
        void display(){
            for(int i = 0; i< n; i++){
                cout << ' ';
                for(int j =0; j<n;j++){
                    if(i!=j){
                        cout<<"0 ";
                        continue;
                    }
                    cout<<A[i];
                    cout<<" ";
                }
                cout << endl;
            }
        }
        ~DiagonalMatrix(){
            cout<<"\nReleasing resouces";
            delete []A;
        }
};
int main(){
    int dimension;
    cin >> dimension;
    int value;
    DiagonalMatrix matrix(dimension);

    for(int i = 0; i< dimension ; i++){
        for(int j = 0; j < dimension; j++){
            cin >> value;
            matrix.set(i,j,value);
        }
    }
    cout<<endl;
    matrix.display();
}