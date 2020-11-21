#include <iostream>
using namespace std;
class Node{

public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
    }
};

class LinkedList{
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;

public:
    void display();
    void add(int data);
    void reverseDisplay();
    void addSorted(int x);
    void removeDup();
    void reverseList();
    int del();
    int del(int index);
    int getSize();
    int getSum();
    int getRecSum();
    int getmax();
    int getRecMax();
    Node * search(int x);
    Node * optSearch(int x);
    Node * insert(int x, int index);
    Node * insert(int x);
    bool isSorted();
    LinkedList operator+(LinkedList list);
    friend LinkedList mergeSorted(LinkedList list1, LinkedList list2 );

private:
    void revD(Node *p){
        if(p){
            revD(p->next);
            cout<<p->data<<" ";
        }
    }
    int sum(Node *p){
        if(p){
            return sum(p->next) + p->data;
        }else{
            return 0;
        }
    }
    int max(Node *p){
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
    void reverse(Node * p, Node * q){
        if(q){
            reverse(p->next, q->next);
            q->next= p;
            
        }else{
            head->next = NULL;
            head = p;
            }
    }
};
LinkedList LinkedList::operator+(LinkedList list){
    Node * p = head;
    while(p->next){
        p = p->next;
    }
    p->next = list.head;
    return *this;
}
void LinkedList::reverseList(){
    reverse(head,head->next);    
}
void LinkedList::removeDup(){
    Node * p = head->next;
    Node * q = head;

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
LinkedList mergeSorted(LinkedList list1, LinkedList list2){
    LinkedList result;
    Node * first = list1.head;
    Node * second = list2.head;
    Node * third = NULL;
    Node * last = NULL;
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
int LinkedList::del(){
    int data = head->data;
    Node * deleteNode = head;
    head = head->next;
    delete deleteNode;   
    return data;
}
int LinkedList::del(int index){
    Node * p = head;
    Node * q = NULL;
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
int LinkedList::getmax(){
    int max = INT16_MIN;
    Node *p = head;
    while (p)
    {   if(max < p->data) max = p->data;
        p = p->next;
    }
    return max;
    
}
int LinkedList::getRecSum(){
    return sum(head);
}

void LinkedList::addSorted(int x){
    Node *p = head;
    Node * node = new Node(x);
    Node * q = NULL;
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


int LinkedList::getSum(){
    int sum = 0;
    Node *p = head;
    while(p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int LinkedList::getRecMax(){
    return max(head);
}
int LinkedList::getSize(){
    return size;
}
Node * LinkedList::insert(int x){
    Node * node = new Node(x);
    node->next = NULL;
    if(head){
        tail->next = node;
        tail = node;  
    }else{
        head = tail = node ; 
    }
    
    return node;
    
}
bool LinkedList::isSorted(){
    bool flag = true;
    Node * p = head;

    while (p->next)
    {
        if(p->data > p->next->data){
            return false;
        }
        p = p->next;
    }
    return flag;
    
}
void LinkedList::add(int data){
    if(head){
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }else{
        head = new Node(data);
        head->next = NULL;
        tail = head;
    }
    size++;
}
void LinkedList::reverseDisplay(){
    revD(head);
}

Node * LinkedList::search(int x){
    Node *p = head;

    while (p)
    {   
        if (p->data == x ) return p;
        p = p->next;
    }
    return NULL;
    
}

Node * LinkedList::optSearch(int x){
    Node * p = head;
    Node * q;
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

Node * LinkedList::insert(int x, int index){
    Node *node = new Node(x);
    Node *p = head;
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

void LinkedList::display(){
    Node *p = head;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){
    LinkedList list;
    LinkedList list2;
    list.add(15);
    list.add(8);
    list.add(5);
    list.add(1);
    cout<<"\nFirst List\n";
    list.display();
    list2.add(16);
    list2.add(12);
    list2.add(9);
    list2.add(3);
    list2.add(1);
    cout<<"\nSecond List\n";
    list2.display();
    cout<<"\nSum of Lists\n";
    mergeSorted(list, list2).display();
    return 0;
}