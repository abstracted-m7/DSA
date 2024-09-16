#include<stdio.h>

int main(){

    int arr[20] = {1, 2, 50, 4, 5};
    int i, j = 0, searchNum = 50, n = 5;

    for(i = 0; i < n; i++){
        printf("arr[%d] = %d ",i,arr[i]);
    }

    while(j < n){
        if (arr[j] == searchNum)
        {
            break;
        }
        j++;        
    }
    printf("\n\nThe element %d is found at %d position.",searchNum,j+1);
}