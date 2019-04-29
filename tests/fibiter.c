#include <stdio.h>
int function(int n) {
    int i, t1 = 0, t2 = 1, nextTerm;

    for (i = 1; i <= n; i = i+1)
    {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return t2;
}
int main()
{
    int x = function(7);
    printf("%d\n",x);
    return 0;
}