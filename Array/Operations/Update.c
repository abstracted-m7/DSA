#include<stdio.h>

int main(){

    int arr[20] = {1, 2, 3, 4, 5}; // First 5 elements are initialized, rest are 0.
    int i, updateNum = 32, pos = 3, n = 5;

    // Printing initial array
    for(i = 0; i < n; i++){
        printf("arr[%d] = %d\n",i,arr[i]);
    }

    // Updating the element at position 3 (index 2)
    arr[pos-1] = updateNum;
    
    printf("\n");

    // Printing updated array
    printf("\nThe updated array is : \n");
    for(i = 0; i < n; i++){
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    
    return 0;
}
