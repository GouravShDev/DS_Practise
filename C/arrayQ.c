#include <stdio.h>


//Single missing element
int findmissing(int a[], int size){
    int m;
    int max=a[0];
    int sum=a[0];
    for(int i = 1; i<size; i++){
        if(max < a[i]) max = a[i];
        sum = sum + a[i];
    }
    m = (max * (max + 1))/2;
    m = m - ((a[0]-1) * (a[0]))/2;
    printf("%d", m);
    return (m - sum);
}

int findMissing2(int a[], int size){
    int m = a[0];
    int i = 1;

    while(a[i] - i == m){
        i++;
    }
    if(i<size){
        return i+m;
    }
    return -1;
    
}

int* findMissingMul(int a[] , int size){
    int m = a[0];
    int i = 1;
    int j = 0;
    int missing[size];
    while(i<size){
        if(a[i] - i != m){
            missing[j++] = i;
            m++;
        }
        i++;
    }
    for(int k = 0; k<size; k++){
        printf("%d ", missing[k]+ a[0]);
    }
}
int main(){
    int a[] = {7,8,9,10,13};
    int size = sizeof(a)/ sizeof(int);
    //int missing = findMissing2(a, size);
    //printf("The missing element is %d", missing);
    findMissingMul(a, size);

}
