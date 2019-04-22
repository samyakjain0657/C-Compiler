#include <stdio.h>

int pant(int a){
    a = a+7;
    return a;
}

int function(int a){
    a = a + 7;
    a = pant(a);
    return a;
}

int main(){
    int a = 3;
    a = function(a);
}