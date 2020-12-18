// Circular queue implementation

#include <stdio.h>

class cirularQueue{
    int *queue;
    int length;
    int first;
    int last;
public:
    cirularQueue(int length){
        this->length = length;
        queue = new int[length];
        first = last = 0;
    }
    bool isEmpty(){
        return (first == last);
    }
    bool isFull(){
        return ((last + 1)%length == first);
    }
    void enqueue(int value){
        if(!isFull()){
            last++;
            last %= length;
            queue[last] = value;
        }else{
            printf("Queue is full");
        }
    }
    void display(){
        for(int i = first+1; i != (last+1)%length ; i++,i %= length){
            printf("%d ", queue[i]);
        }
    }
    void dequeue(){
        if(!isEmpty()){
            first = (first+1) % length;
            queue[first] = 0; 
        }else{
            printf("Queue is empty");
        }
    }
};

int main(){
    cirularQueue queue(5);
    queue.enqueue(4);
    queue.enqueue(6);
    queue.enqueue(5);
    queue.enqueue(2);
    queue.dequeue();
    queue.display();
    queue.enqueue(42);
    queue.enqueue(13);
    printf("\n");
    queue.display();
    return 0;
}