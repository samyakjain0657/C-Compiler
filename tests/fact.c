#include <stdio.h>

int factorial(int a, int b){
    if(a == 0){
        return b;
    }
    b = a*factorial(a-1, b);
    return b;
}

int main(){
    int a = 3, b = 1, fact;
    fact = factorial(factorial(a,1), b);
    printf("%d\n",fact);
    return 0;
}