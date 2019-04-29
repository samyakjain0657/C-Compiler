#include <stdio.h>

float z=0;

void increaseGlobalLog(int x){
    if(x==0){
        return;
    }
    z++;
    increaseGlobalLog(x/2);
}

int main(){
    int a[5];
    increaseGlobalLog(1);
    int x = z;
    return 1;
}

