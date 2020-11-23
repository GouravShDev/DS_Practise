#include <iostream>
using namespace std;

template <class T>
class Node{

public:
    T data;
    Node *next;

    Node(T data){
        this->data = data;
    }
};
template <class T>
class LinkedList{
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    int size = 0;

public:
    void display();
    void add(T data);
    void reverseDisplay();
    void addSorted(T x);
    void removeDup();
    void reverseList();
    T del();
    T del(int index);
    int getSize();
    int getSum();
    int getRecSum();
    T getmax();
    T getRecMax();
    Node<T> * search(T x);
    Node<T> * optSearch(T x);
    Node<T> * insert(T x, int index);
    Node<T> * insert(T x);
    bool isSorted();
    bool isLoop();
    LinkedList operator+(LinkedList list);
    //friend LinkedList<T> mergeSorted<>(LinkedList<T> list1, LinkedList<T> list2);
    void createLoop();


private:
    void revD(Node<T> *p){
        if(p){
            revD(p->next);
            cout<<p->data<<" ";
        }
    }
    int sum(Node<T> *p){
        if(p){
            return sum(p->next) + p->data;
        }else{
            return 0;
        }
    }
    T max(Node<T> *p){
        if(p){
            return p->data > max(p->next)? p->data : max(p->next);
            // if(p->data > max(p->next)){
            //     return p->data;
            // }else{
            //     return max(p->next);
            // }
        }else{
            return 0;
        }
    }
    void reverse(Node<T> * p, Node<T> * q){
        if(q){
            reverse(p->next, q->next);
            q->next= p;
            
        }else{
            head->next = NULL;
            head = p;
            }
    }
};
template <class T>
LinkedList<T> LinkedList<T>::operator+(LinkedList list){
    Node<T> * p = head;
    while(p->next){
        p = p->next;
    }
    p->next = list.head;
    return *this;
}
template <class T>
void LinkedList<T>::reverseList(){
    reverse(head,head->next);    
}
template <class T>
void LinkedList<T>::removeDup(){
    Node<T> * p = head->next;
    Node<T> * q = head;

    if(q){
        while(p){
            if(q->next != p){
                q = q->next;
            }
            while (p && p->data == q->data)
            {
                q->next = p->next;
                delete p;
                p = q->next;
            }
            if(p){
                p = p->next; 
            }
            
            
        }
    }
}
template <class T>
LinkedList<T> mergeSorted(LinkedList<T> list1, LinkedList<T> list2){
    LinkedList<T> result;
    Node<T> * first = list1.head;
    Node<T> * second = list2.head;
    Node<T> * third = NULL;
    Node<T> * last = NULL;
    if(first->data > second->data){
        third = last = second;
        second = second->next;
        last->next = NULL;
    }else{
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    result.head = third;
    while(first && second){
        if(first->data > second->data){
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }else{
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
    }
    if(first){
        last->next = first;
    }
    if(second){
        last->next = second;
    }   
    
    return result;
    
}
template <class T>
T LinkedList<T>::del(){
    T data = head->data;
    Node<T> * deleteNode = head;
    head = head->next;
    delete deleteNode;   
    return data;
}
template <class T>
T LinkedList<T>::del(int index){
    Node<T> * p = head;
    Node<T> * q = NULL;
    int data;
    if(index == 0){
        data = del();
    }
    else if(p){
        while(p->next &&index>0){
            q = p;
            p = p->next;
            index--;
        }
        if(q){
            q->next = p->next;
            data = p->data;
            delete p;
        }/*else
        {
            head = p->next;
            data = p->data;
            delete p;
            return data;

        }*/  

    }
    return data;
}
template <class T>
T LinkedList<T>::getmax(){
    int max = INT16_MIN;
    Node<T> *p = head;
    while (p)
    {   if(max < p->data) max = p->data;
        p = p->next;
    }
    return max;
    
}
template <class T>
int LinkedList<T>::getRecSum(){
    return sum(head);
}
template <class T>
void LinkedList<T>::addSorted(T x){
    Node<T> *p = head;
    Node<T> * node = new Node<T>(x);
    Node<T> * q = NULL;
    if(p){
        while(p && p->data<x){
            q = p;
            p = p->next;
        }
        if(q){
          node->next = q->next;
          q->next = node;
          size++; 
        }else{
            node->next = p;
            head = node;
            size++;
        }
        
    }else{
        node->next = NULL;
        head =node;
        tail = node;
        size++;
    }
}
template <class T>
void LinkedList<T>::createLoop(){
    tail->next = head;
}
template <class T>
bool LinkedList<T>::isLoop(){
    Node<T> * p = head;
    Node<T> * q = p;

    while(q && p){
        p = p->next;
        q = q->next->next;
        q = q ? q->next: NULL;
        if( q == p){
            return true;
        }
    }
    return false;
}
template <class T>
int LinkedList<T>::getSum(){
    int sum = 0;
    Node<T> *p = head;
    while(p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}
template <class T>
T LinkedList<T>::getRecMax(){
    return max(head);
}
template <class T>
int LinkedList<T>::getSize(){
    return size;
}
template <class T>
Node<T> * LinkedList<T>::insert(T x){
    Node<T> * node = new Node<T>(x);
    node->next = NULL;
    if(head){
        tail->next = node;
        tail = node;  
    }else{
        head = tail = node ; 
    }
    
    return node;
    
}
template <class T>
bool LinkedList<T>::isSorted(){
    bool flag = true;
    Node<T> * p = head;

    while (p->next)
    {
        if(p->data > p->next->data){
            return false;
        }
        p = p->next;
    }
    return flag;
    
}
template <class T>
void LinkedList<T>::add(T data){
    if(head){
        Node<T> *node = new Node<T>(data);
        node->next = head;
        head = node;
    }else{
        head = new Node<T>(data);
        head->next = NULL;
        tail = head;
    }
    size++;
}
template <class T>
void LinkedList<T>::reverseDisplay(){
    revD(head);
}
template <class T>
Node<T> * LinkedList<T>::search(T x){
    Node<T> *p = head;

    while (p)
    {   
        if (p->data == x ) return p;
        p = p->next;
    }
    return NULL;
    
}
template <class T>
Node<T> * LinkedList<T>::optSearch(T x){
    Node<T> * p = head;
    Node<T> * q;
    while (p)
    {   
        q = p;
        if(p->data == x) {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        
        p = p->next;
    }
    
    return NULL;
    
}
template <class T>
Node<T> * LinkedList<T>::insert(T x, int index){
    Node<T> *node = new Node<T>(x);
    Node<T> *p = head;
    if(index < 0 || index > size) return NULL;
    if(index==0){
        add(x);
        return head;
    }
    for(int i=1; i<index && p;i++){
        p=p->next;
    }
    if(p){
        node->next = p->next;
        p->next = node;
    }
    return node;
}
template <class T>
void LinkedList<T>::display(){
    Node<T> *p = head;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){
    LinkedList<string> list;
    LinkedList<string> list2;
    list.add("first");
    list.add("Second");
    list.add("third");
    list.add("fourth");
    cout<<"\nFirst List\n";
    list.display();
    list2.add("1");
    list2.add("2");
    list2.add("3");
    list2.add("4");
    list2.add("5");
    cout<<"\nSecond List\n";
    list2.display();
    cout<<"\nSum of Lists\n";
    return 0;
}