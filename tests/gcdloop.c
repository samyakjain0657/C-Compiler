#include <stdio.h>

int main() {
    int a = 72, b = 63;
    while (1 == 1) {
        if (a == 0 || b == 0) {
            break;
        }
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a != 0) {
        printf("%d\n",a);
    }
    if (b != 0) {
        printf("%d\n",b);
    }
    return 0;
}