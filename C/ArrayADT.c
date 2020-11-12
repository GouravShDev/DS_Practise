#include <stdio.h>

struct Array{
    int A[10];
    int size;
    int length;
};
void append(struct Array *a, int value){
    if(a->length < a->size){
    a->A[a->length++] = value;
    }
}
void Display(struct Array a){
    int i;
    for(i=0;i<a.size;i++){
        printf(" %d ", a.A[i]);
    }
}
void insert(struct Array *a, int index, int value){
    if(index < a->length&& index > 0){
    int i;
    for(i=a->length; i>index;i--){
        a->A[i] = a->A[i-1];
    }
    a->A[index] = value;
    }
}
int Delete(struct Array *a, int index ){
    int i;
    int x = 0;
    if(index >= 0 && index < a->length){
        x = a->A[i];
        for(i=index; i<a->length-1;i++){
            a->A[i] = a->A[i+1];
        }
        a->length--;
    }
    return x;
}
int Search(int a, int value){
    return binarySearch(0, 5,a, value);
}
int LinearSearch(struct Array *a,int value){
    int i;
    for(int i=0; i< a->length;i++){
        if(a->A[i] == value){
            swap(&a->A[i],&a->A[0]);
            return 0;
        }
    }
    return -1;
    
}
void swap(int *x , int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int binarySearch(int l, int h,int a[], int value){
    int mid = (l+h)/2;
    if(a[mid] == value){
        return mid;
    }
    if(l==h){
        return -1;
    }
    if(a[mid] > value){
        return binarySearch(l,mid-1,a,value);
    }else{
        
        return binarySearch(mid+1,h,a,value);
    }
    return -1;
}

void Reverse(int a[]){
    int *b;
    b = (int *) malloc(6);
    int i , j;
    int length_a =sizeof(a)/ sizeof(a[0]); 
    for(i=0,j=5; j>=0;i++, j-- ){
        b[i] = a[j];
    }
    for(i=0; i< 6; i++ ){
        a[i] = b[i];
    }   
}
void insertInSorted(int value, int a[], int length){
    for(int i = length-1; i >= 0; i--){
        a[i+1] = a[i];
        if(a[i] <= value){
            a[i+1] = value;
            break;
        }
        if(i==0){
            a[i] = value;
        }

    }
}
int main(){
    struct Array array = {{1,2,4,6,15,63},10,6};
    /*append(&array, 9);
    append(&array, 123);
    append(&array, 13);
    insert(&array, 10, 141);*/
    Display(array);
    //printf("\nThe Value deleted is %d \n", Delete(&array, 5));
    printf("**********************\n");
    /*Display(array);
    printf("\nThe index of %d is %d", 2,LinearSearch(&array, 2));
    printf("\nThe index of %d is %d\n", 114,LinearSearch(&array, 114));
    Display(array);*/
    //int in = Search(array.A,154);
    //printf("\n The index of %d: %d",1, in);
    insertInSorted(45, array.A, array.length);
    Display(array);
    return 1;
}