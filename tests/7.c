#include <stdio.h>

float z=0;

int main(){
    increaseGlobalLog(5);//final z=3
    return 1;
}

void increaseGlobalLog(int x){// semantic error: should be before main
    if(x==0){
        return;
    }
    z++;
    increaseGlobalLog(x/2);
}