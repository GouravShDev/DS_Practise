#include <stdio.h>


class Queue{
int last;
int first;
int *arr;
int size;
public:
    Queue(int len){
        size = len;
        first = last = -1;
        arr = new int[len];
    }
    bool isEmpty(){
        return (last == first);
    }
    bool isFull(){
        return (last == size+1);
    }
    void enqueue(int value){
        arr[++last] = value;
    }
    void dequeue(){
        arr[++first] = 0;
    }
    void display(){
        for(int i = first+1; i <=last ; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

};

int main(){
    int size;
    size = 5;
    Queue *q = new Queue(size);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);
    q->display();
    printf("\n************\n");
    q->dequeue();
    q->display();
    return 0;
}