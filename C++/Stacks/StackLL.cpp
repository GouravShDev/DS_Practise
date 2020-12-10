#include <iostream>
using namespace std;

class Node{

public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class LinkedList{
    Node *top = NULL;
public:
    void insert(int data){
        if(top){
            Node *node = new Node(data);
            node->next = top;
            top = node;
        }else{
            top = new Node(data);
        }
    }
    int  del(){
        int r;
        Node *p = top;
        if(top){
            top = p->next;
            r = p->data;
            delete p;
            return r;
        }else{
            return -1;
        }
    } 
    void display(){
        Node *p = top;
        if(!p) return;
        while(p){
            cout<<p->data<<" ";
            p = p->next;
        }
    } 
    int peak(){
        return top->data;
    } 
};

class Stack{
  LinkedList list;

public:
    void push(int value){
        list.insert(value);
    }
    void display(){
        list.display();
    }
    int pop(){
        return list.del();
    }
    int peak(){
        return list.peak();
    }

};

int main(){
    Stack stack;
    stack.push(3);
    stack.push(5);
    stack.push(51);
    cout<<stack.pop();
    //stack.display();
    return 0;
}