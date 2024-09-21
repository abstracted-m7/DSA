// Using sliding Window technique we solve the maximum sub array problem

#include<stdio.h>

int main()
{
    int arr[20] = {1, 2, 4, 5, 6, 8, 10, 12};
    int i, subArraySize = 4, n = 8;
    int current = 0, max, start_idx = 0;

    for ( i = 0; i < subArraySize; i++)
    {
        current += arr[i];
    }

    max = current;

    for ( i = 1; i <= n - subArraySize; i++)
    {
        current = current - arr[i-1] + arr[i + subArraySize - 1];

        if (current > max)
        {
            max = current;
            start_idx = i;
        }
        
    }

    printf("The maximum sum is = %d ",max);
    printf("\nThe sub array is : ");
    for ( i = start_idx; i < start_idx + subArraySize; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;   
     
}