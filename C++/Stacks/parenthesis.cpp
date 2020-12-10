#include <iostream>

using namespace std;

template <class T>
class Stack{
    T *arr;
    int topIndex;
    int size;

public:
    Stack(int size){
        this->size = size;
        arr = new T[size];
        topIndex = 0;
    }
    void push(T value){
        if(topIndex < size){
            arr[topIndex++] = value;
        }
    }
    T pop(){
        if(!isEmpty()){
            T x = arr[--topIndex];
        return x;
        }else{
            return -1;
        }
        
    }
    T peek(){
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

bool checkBalance(Stack<char> *st, string s){
    for(int i=0; i< s.length(); i++){
        if(s[i] == '('){
            st->push('(');
        }else if(s[i] == ')'){
            if(st->isEmpty()){
                cout<<"Not balanced";
                return false;
            }else{
                st->pop();
            }
        }
    }
    if(st->isEmpty()){
        cout<<"Balanced";
        return true;
    }else{
        cout<<"Not balanced";
        return false;
    }
}
bool checkBalance2(Stack<char> *st, string s){
    for(int i=0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st->push(s[i]);
        }else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            int x = st->pop();
            if(s[i] == ')'){
                if(x != '('){
                    cout<<"Not Balanced";
                    return false;
                }
            }else if(s[i] == ']'){
               if(x != '['){
                    cout<<"Not Balanced";
                    return false;
                }
            }else if(s[i] == '}'){
                if(x != '{'){
                    cout<<"Not Balanced";
                    return false;
                }
            }
        }
    }
    if(st->isEmpty()){
        cout<<"Balanced";
        return true;
    }else{
        cout<<"Not balanced";
        return false;
    }
}

int main(){
    //int size;
    string s;
    //cin>>size;
    Stack<char> *st = new Stack<char>(10);
    cin>>s;
    checkBalance2(st, s);

    
}