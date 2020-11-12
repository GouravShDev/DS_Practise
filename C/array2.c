#include <stdio.h>
#include <stdbool.h>

void dup(int a[], int size){
    int count;
    bool f;   
    for(int i=0; i<size; i++){
        count=0;
        f = false;
        for(int j = i+1; j<size;j++){
            if(a[i] == a[j]){
                count++;
                a[j] = -1; 
                f= true;
            }
        }
        if(f) printf("%d count is %d\n", a[i], count);
    } 
}
void display(int a[] , int size){
    for(int i =0; i<size; i++){
        printf("%d ", a[i]);
    }
}
int main(){
    int a[] = {5,2,1,4,5};
    /*int b[] = {4,10,12,22,23};
    int a_length = sizeof(a) / sizeof(int);
    int b_length = sizeof(a) / sizeof(int);
    int c[a_length+b_length];
    int i , j, k;
    i=0,j=0,k=0;
    
    while(k!=a_length+b_length){
        if(a[i] < b[j]){
            c[k] = a[i];
            i++;
        }else{
            c[k] = b[j];
            j++;
        }
        k++;
    }
    for(; i<a_length;i++) c[k++] = a[i];
    for(; j<b_length;j++) c[k++] = a[j];
    for(k=0; k< a_length+b_length;k++){
        printf(" %d ", c[k]);
    }*/
    dup(a,5);
    display(a, 5);
    return 1;
}
