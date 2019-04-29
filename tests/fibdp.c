#include <stdio.h>

int f[30];

int fib(int n){ 
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }    
    if (n >= 30){
        return -1;        
    }
    if (f[n] != -1) {
        return f[n];
    }
    int temp = fib(n-1) + fib(n-2);
    f[n] = temp;
    return f[n]; 
} 
  
int main (){ 
    int n = 9; 
    int i;
    for (i = 0; i < 30; i++) {
        f[i] = -1;
    }
    for (i = 0; i < 10; i++) {
        int temp = fib(i);
        printf("%d\n",temp); 
    }
    return 0; 
}