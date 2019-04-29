#include <stdio.h>

int main() {
    int a = 1;
    int b = 6;
    int c = 7;
    switch (a){
    case 1:
        printf("%d\n",b);
        break;
    case 2:
        printf("%d\n",c);
    default:
        printf("%d\n",a);
        break;
    }
    
}