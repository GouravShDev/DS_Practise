// Program to convert infix to postfix

#include <stdio.h>
#include<string.h>
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
                    while(stack.isNotEmpty() && getPrec(stack.peek()) >= getPrec(str[i])){
                        ps[j++] = stack.pop();
                    }
                    stack.push(str[i]);
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
    ps[j] = NULL;
    return ps;
} 

char *postFix2(char *str, int len){
    char *ps = new char[len];
    Stack stack;
    int j=0,i=0;
    while(i<len){
        if(getPrec(str[i])){
            if(stack.isNotEmpty()){
                if(getPrec(stack.peek())< getPrec(str[i])){
                    stack.push(str[i++]);
                }else{
                    ps[j++] = stack.pop();
                }
            }else{
                stack.push(str[i++]);
            }
        }else{
            ps[j++] = str[i++];
        }
    }
    while (stack.isNotEmpty())
    {
        ps[j++] = stack.pop();
    }
    ps[j] = NULL;
    return ps;

}


int getOutPre(char x){
    if(x == '+' || x == '-'){
        return 1;
    }else if(x == '*' || x == '/'){
        return 3;
    }else if(x == '^'){
        return 6;
    }else if(x == '('){
        return 7;
    }else if(x == ')'){
        return 0;
    }else{
        return -1;
    }
}


int getInPre(char x){
    if(x == '+' || x == '-'){
        return 2;
    }else if(x == '*' || x == '/'){
        return 4;
    }else if(x == '^'){
        return 5;
    }else if(x == '('){
        return 0;
    }
    return NULL;
}
char *postFixComp(char *str, int len){
    char *ps = new char[len];
    Stack stack;
    int i,j;
    i = j = 0;
    while(i<len){
        if(getOutPre(str[i]) != -1){
            if(stack.isNotEmpty()){
                if(getInPre(stack.peek()) < getOutPre(str[i])){
                    stack.push(str[i++]);
                }else if(getInPre(stack.peek()) > getOutPre(str[i])){
                    ps[j++] = stack.pop();
                }else{
                    stack.pop();
                }
            }else{
                if(str[i] != ')'){
                   stack.push(str[i++]); 
                }else
                {
                    i++;
                }      
                
            }
        }else{
            ps[j++] = str[i++];
        }
    }
    while(stack.isNotEmpty()){
        ps[j++] = stack.pop();
    }
    ps[j] = NULL;
    return ps;
}

int evaluate(char *str, int len){
    int i = 0;
    char res;
    Stack stack;
    while(i<len){
        if(getPrec(str[i])){
            int op1,op2;
            op2 =  stack.pop();
            op1 = stack.pop();
            if(str[i] == '+'){
                res = op1 + op2;
            }else if(str[i] == '-'){
                res = op1 - op2;
            }else if (str[i] == '*'){
                res = op1 * op2;
            }else if(str[i] == '/'){
                res = op1 / op2;
            }
            stack.push(res);
            i++;
        }else{
            stack.push(str[i++]- '0' );
        }
    }
    return stack.pop();
}

int main(){
    char *str;
    int num = 20;
    str = new char[num];
    scanf("%s", str);
    printf("%s",postFixComp(str, strlen(str)));
    printf("\nSolved Epression is ");
    printf("\n%d", evaluate(postFixComp(str, strlen(str)), strlen(str)) );
    return 0;
}