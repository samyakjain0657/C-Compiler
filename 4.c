#include <stdio.h>

int main() {
    if (4 > 3) {
        if (5 > 3) {
            printf("1\n");
            break;
        }
        if (6 > 4) {
            printf("2\n");
            break;
            continue;
        }
        if (5 > 4) {
            printf("3\n");
            break;
        }
    }
}