// Queue using Linked List

#include <stdio.h>

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;

    }
    Node(){}
};

class Queue
{

    Node *first;
    Node *last;

public:
    Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int value);
    int dequeue();
    void display();
};
Queue::Queue()
{
    first = NULL;
    last = NULL;
}
bool Queue::isEmpty()
{
    return first == NULL;
}
bool Queue::isFull()
{
    bool full = false;
    Node *p = new Node;
    full = (p == NULL);
    return full;
}
void Queue::enqueue(int value)
{
    Node *node = new Node(value);
    if (!isEmpty())
    {
        last->next = node;
        last = node;
    }
    else
    { 
        first= node;
        last = node;
    }
}
int Queue::dequeue()
{
    int remValue = -1;
    if (!isEmpty())
    {
        remValue = first->data;
        Node *p = first;
        first = first->next;
        delete p;
    }
    return remValue;
}

void Queue::display(){
    Node *p = first;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    Queue queue;
    queue.enqueue(4);
    queue.enqueue(2);
    queue.enqueue(8);
    queue.display();
    printf("**********\n");
    queue.dequeue();
    queue.display();
    return 0;
}