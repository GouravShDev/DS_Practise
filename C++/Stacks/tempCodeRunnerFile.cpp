// Program to convert infix to postfix

#include <stdio.h>

class Node{

public:
    char data;
    Node *next;

    Node(char data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
    Node *head;

public:
    Stack(){
        head = NULL;
    }

    char peek(){
        if(head){
            return head->data;
        }else{
            return NULL;
        }
        

    }
    char pop(){
        if(!head) return NULL;
        Node *p = head;
        char delData = head->data;
        head = head->next;
        delete p;
        return delData;
    }
    void push(char data){
        Node *node = new Node(data);
        if(head){
            node->next = head;
            head = node;
        }else{
            node->next = head;
            head = node;
        }
    }
    void display(){
        Node *p = head;
        while (p)
        {
            printf("%c",p->data);
            p = p->next;
        }
        
    }
    bool isEmpty(){
        return head == NULL;
    }
    bool isNotEmpty(){
        return head!=NULL;
    }

};
int getPrec(char c){
    if(c == '+' || c == '-'){
        return 1;
    }else if (c == '*' || c == '/')
    {
        return 2;
    }else{
        return 0;
    }   
}
char * postFix(char *str, int len){
    char *ps = new char[len];
    Stack stack;
    int j = 0;
    for(int i =0; i<len; i++){
        if(getPrec(str[i])){
            if(stack.isNotEmpty()){
                if(getPrec(stack.peek()) < getPrec(str[i])){
                    stack.push(str[i]);
                }else{
                    while(!stack.isEmpty() && getPrec(stack.peek()) > getPrec(str[i])){
                        ps[j++] = stack.pop();
                    }
                }
            }else{
                stack.push(str[i]);
            }
        }else{
            ps[j++] = str[i];
        }
    }
    while (stack.isNotEmpty())
    {
        ps[j++] = stack.pop();
    }
    
    return ps;
} 
int main(){
    char *str;
    int num = 6;
    str = new char[num];
    scanf("%s", str);
    printf("%s",postFix(str, num));

    return 0;
}