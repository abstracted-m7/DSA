#include<stdio.h>

int main(){
    int arr[10] = {5, 2, 1, 6, 4, 8, 12, 10};
    int i, n = 8, max1, max2;

    if(arr[0] > arr[1]){
        max1 = arr[0];
        max2 = arr[1];
    }else{
        max1 = arr[1];
        max2 = arr[0];
    }

    for(i = 2; i <= n; i++){

        if(arr[i] > max1){

            max2 = max1;
            max1 = arr[i];

        }
        else if (arr[i] > max2)
        {
            max2 = arr[i];
        }
    }
    printf("\nThe top most element is = %d",max1);
    printf("\nSecond largest element is = %d\n", max2);
    return 0;
}