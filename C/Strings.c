#include <stdio.h>

int main(){
    char s[] = "findiindsfng";
    long int x,z;
    x = z = 0;
    for(int i=0 ; s[i]!='\0';i++){
        x =1;
        x = x << s[i] - 97;
        //int g = ;
        if((x&z) > 0){
            printf(" duplicate is %c \n", s[i]);
        }else{
            z = x | z;
        }
    }

}