#include <stdio.h>
/*

a = 6
hujik
*/

float product(float a,float b){
    if(b<1){
        return a*b;
    }
    return a+product(a,b-1);
}
//main
int main(){
    int z=0;
    float x=1.5,v=x/z;
    float c=product(5.0,4.2);
    for(z=0;;){
        int a;
    }
    return 0;
}