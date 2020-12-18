// Solution for tower of hanoi

#include <stdio.h>


void towerOFHanoi(int noOfDisc, char A, char B, char C){
    if(noOfDisc == 1){
        printf("Mov 1 disc from %c to %c using %c\n", A,C,B);
        return;
    }else{
        towerOFHanoi(noOfDisc-1, A, C, B );
        towerOFHanoi(1, A, B, C );
        towerOFHanoi(noOfDisc-1, B, A, C );

    }

}



int main(){
    int disc;
    scanf("%d", &disc);
    towerOFHanoi(disc, 'A', 'B', 'C');
    return 0;
}