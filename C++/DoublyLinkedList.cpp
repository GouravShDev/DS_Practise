#include <iostream>
using namespace std;

template <class T>
class Node{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

template <class T>
class DoublyLinkedList{
    Node<T> *head;
    Node<T> *tail;
public:
    DoublyLinkedList(){
        head = NULL;
    }
    void insert(T value){
        Node<T> *node = new Node<T>(value);
        if(head){
            head->prev = node;
        }else{
            tail = node;
        }
        node->next = head;
        head = node;
    }
    void display(){
        Node<T> *p = head;
        while(p){
            cout<<p->data<<" ";
            p = p->next;
        }

    }
    void revDisplay(){
        Node<T> *p = tail;
        while(p){
            cout<<p->data<<" ";
            p = p->prev;
        }
    }
    T del(){
        Node<T> * p = head;
        T delValue = -1;
        head = p->next;
        delValue = p->data;
        p->next->prev = NULL;
        delete p;
        return delValue;
    }

    T del(int index){
        T delValue = -1;
        if(index == 0){
            delValue = del();
        }else{
            Node<T> *p = head;
            Node<T> *q = NULL;
            for(int i =0; i < index - 1; i++){
                p = p->next;
            }
            q = p->next;
            p->next = p->next->next;
            if(q->next) q->next->prev = p;
            delValue = q->data;
            delete q;
        }
        return delValue;

    }
    void insert(int index,T value){
        if(index == 0){
            insert(value);
        }else
        {
            Node<T> *p = head;
            Node<T> *node = new Node<T>(value);
            for(int i = 0; i<index -1 ; i++){
                p = p->next;
            }
            node->next = p->next;
            node->prev = p;
            p->next = node;
            if(node->next) node->next->prev = node;
        }
        
    }
    void reverse(){
        Node<T> * p = head;
        Node<T> * q = NULL;

        do{
            p->prev = p->next;
            p->next = q;
            q = p;
            p = p->prev;
        }while(p);
        head = q;
    }
};

int main(){
    DoublyLinkedList<int> list;
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(8);
    //list.del(3);
    //list.reverse();
    list.insert(1, 11);
    list.display();

    return 0;
}