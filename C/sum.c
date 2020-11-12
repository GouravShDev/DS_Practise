#include <stdio.h>


int power(int m , int n ){
    if(n == 0){
        return 1;
    }else{
        return power(m, n-1)*m;
    }

}
int factorial(int f){
    if(f == 1 || f == 0){
        return 1;
    }else{
        return factorial(f-1)*f;
    }

}
int sum(int n){
    if(n==0){
        return 0;
    }else{
        return sum(n-1) + n;
    }
}  
int tay(int x, int n){
    int s;
    if(n==0){
        return 1;
    }else{
        s = power(x, n)/ factorial(n);
        return s+ tay(x, --n);
    }
}
int fib(int n ){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fib(n-2) + fib(n-1);
}
int comb(int n , int r){
    if(r == 0){
        return 1;
    }else{
        return n * comb(n-1, r-1);
    }
}
int nCr(int n, int r){
    if(r==0 || n-r == 0){
        return 1;
    }
    return comb(n, r)/r;
}
int main(){
    int m;
    /*scanf("%d", &m);
    printf("Input is %d", m );*/
    printf("Output %d", nCr(10,5));
    return 1;

} 


