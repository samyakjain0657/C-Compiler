#include <stdio.h>
int power(int x, int y, int p) 
{ 
    int res = 1;  
    x = x % p;  
    while (y > 0) 
    {
        if (y % 2 == 1)  {
            res = (res*x) % p; 
        }
        y = y / 2;
        x = (x*x) % p;   
    } 
    return res; 
} 

int main() {
    int x = -6;
    int y = 5;
    int mod = 1000000007;
    int res = power(x,y,mod);
    printf("%d\n",res);
    return 0;
}