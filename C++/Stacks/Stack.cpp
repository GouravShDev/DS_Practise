#include <iostream>
using namespace std;

class Stack{
    int *arr;
    int topIndex;
    int size;

public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        topIndex = 0;
    }
    void push(int value){
        if(topIndex < size){
            arr[topIndex++] = value;
        }
    }
    int pop(){
        if(!isEmpty()){
            int x = arr[--topIndex];
        return x;
        }else{
            return -1;
        }
        
    }
    int peek(){
        return arr[topIndex-1];
    }
    void display(){
        for(int i =0; i < topIndex ; i++){
            cout<<arr[i]<<" ";
        }
    }
    bool isEmpty(){
        return !topIndex;
    }
    bool isFull(){
        return (topIndex == size);
    }
};

int main(){
    int size;
    cout<<"Enter size of Stack : ";
    cin>>size;
    Stack stack(size);

    stack.push(5);
    stack.push(2);
    stack.push(6);
    stack.display();
    //cout<<"\nAfter Pop \n";

    //stack.pop();
    // stack.display();
    //cout<<"\nPeek output\n";
    //cout<<stack.peek();
    // cout<<"\n";
    // //stack.display();
    // if(stack.isEmpty()){
    //     cout<<"Stack is empty";
    // }else{
    //     cout<<"Stack is not empty";
    // }
    // cout<<endl;

    // if(stack.isFull()){
    //     cout<<"Stack is Full";
    // }else
    // {
    //     cout<<"Stack is not full";
    // }
    
}