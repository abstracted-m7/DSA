#include<stdio.h>

int main(){

    int arr[20] = {1, 2, 30, 4, 5};
    int i, num_idx = 3, n = 5;

    for( i = 0; i < n; i++){
        printf("arr[%d] = %d ",i,arr[i]);
    }

    while(num_idx < n){
        arr[num_idx - 1] = arr[num_idx];
        num_idx++;
    }
    n--;
    printf("\n\n");
    for(i = 0; i < n; i++){
        printf("arr[%d] = %d ",i,arr[i]);
    }

    return 0;
}