#include<stdio.h>

int main(){

    int arr[20] = {16, 6, 8, 32, 12};
    int i, pos, num, n = 5;

    for(i = 0; i < n; i++){
        printf("arr[%d] = %d ",i,arr[i]);
    }

    printf("\n\n");

    pos = 4, num = 99;
    n++;

    for(i = n-1; i >= pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos-1] = num;

    for(i = 0; i < n; i++){
        printf("arr[%d] = %d ",i,arr[i]);
    }
    return 0;
}