#include <stdio.h> 
  
int main(){ 
    int arr[8], n = 8, j, a;
    for(j=0; j<n; j++){
        arr[j] = n-j;
    }
    int i; 
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }      
    }
    for(i=0; i<n; i++){
        a = arr[i];
        printf("%d",a);
    }
    return 0; 
} 