#include <stdio.h>

int main(){
    float n=2.5;
    int c=625;
    while(c!=0){
        if(c%25==0){
            n*=1+0.5+0.5;
        }
        else{
            n*=2+0.8+0.7-1.0/2+1/2;
        }
        c/=5;
    }
    printf("%f\n",n);
    return 1;
}