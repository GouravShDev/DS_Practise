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
    int size = 0;

public:
    void display();
    void add(int data);
    void reverseDisplay();
    int getSize();
    int getSum();
    int getRecSum();
    int getmax();
    int getRecMax();
    Node * search(int x);
    

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
};
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
void LinkedList::add(int data){
    if(head){
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }else{
        head = new Node(data);
        head->next = NULL;
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

void LinkedList::display(){
    Node *p = head;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){
    LinkedList list;
    list.add(14);
    list.add(4);
    list.add(6);
    list.display();
    return 0;
}