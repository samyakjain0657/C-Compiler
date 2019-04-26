#include <stdio.h>

int factorial(int a, int b){
    if(a == 0){
        return b;
    }
    b = a * factorial(a-1, b);
}

int b = 5;
int fact(int a){
    a = b;
    return a;
}

int main(){
    int a = 5 + 3, b = 1;
    fact = factorial(fact(a), b);
}