#include<stdio.h>

int main(){
    int arr[2][3];
    int i, j, row = 2, column = 3;

    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            printf("Enter value of arr[%d][%d] = ",i,j);
            scanf("%d" , &arr[i][j]);
        }
    }

    printf("\n\n");

    printf("The 2D Matrix is : ");
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}