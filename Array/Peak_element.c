// // Find a peak element which is not smaller then its neighbours.

#include<stdio.h>

int main()
{
    int arr[] = {10, 20, 15, 2, 23, 90, 90,10};
    int i,  size = sizeof(arr) / sizeof(arr[0]);

    if (size == 1)
    {
        printf("\nThe array has only one element.\n");
    }
    else if (arr[0] > arr[1])
    {
        printf("\nThe peak element is = %d ",arr[0]);
    }
    else if (arr[size - 1] > arr[size - 2])
    {
        printf("\nThe peak element is = %d ",arr[size - 1]);
    }
    else
    {   
        printf("\nThe peak elements is : ");
        for ( i = 1; i < size; i++)
        {
            if (arr[i] >= arr[i - 1] && arr[i] >= arr[i+1])
            {
                printf("%d ",arr[i]);
            }
            
        }
    }
    
    return 0;
}
