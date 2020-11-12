#include<stdio.h>
int main(){
    int *p;
    p = (int *) malloc(5 * sizeof(int));

    p[0] = 1;
    p[1] = 3;
    p[2] = 4;
    p[3] = 5;
    p[4] = 6;

    for(int i =0 ; i < 5 ; i++){
        printf("Value at index: %d is %d at address %d \n", i, p[i], &p[i]);
    }
    free(p);
    p = NULL;

    return 1;
}