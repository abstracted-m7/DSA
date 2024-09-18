// Using Naive Approch

#include<stdio.h>

int main(){
    int arr[20] = { 1, 2, 4, 5, 6, 8, 10, 12};
    int i, j, subArraySize = 4, n = 8;
    int current, max = -100,  start_idx = 0;

    for(i = 0; i <= n-subArraySize; i++)
    {
        current = 0;

        for(j = i; j < i+subArraySize; j++)
        {
            current = current + arr[j];
        }
        if(current > max)
        {
            max = current;
            start_idx = i;
        }
    }
    printf("\n\nThe maximum sum = %d ",max);
    printf("\nThe sub array is : ");
    for (i = start_idx; i < start_idx + subArraySize; i++)
    {
        printf("%d ",arr[i]);
    }
    
}