// Find common elements in three sorted array.

// Time Complexity : O(n1 + n2 + n3)
// Space Complexity : O(1)

#include<stdio.h>
int main()
{
    int arr1[] = {1, 5, 10, 20, };
    int arr2[] = {1, 2, 4, 6, 8, 10};
    int arr3[] = {1, 2, 3, 4, 5};

    int size_arr1 = sizeof(arr1) / sizeof(arr1[0]);
    int size_arr2 = sizeof(arr2) / sizeof(arr2[0]);
    int size_arr3 = sizeof(arr3) / sizeof(arr3[0]);

    int i = 0, j = 0, k = 0;

    printf("\nCommon Elements are : ");

    while (i < size_arr1 && j < size_arr2 && k < size_arr3)
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            printf("%d ",arr1[i]);
            i++ , j++ , k++;
        }
        else if( arr1[i] < arr2[j] )
        {
            i++;
        }
        else if ( arr2[j] < arr3[k] )
        {
            j++;
        }
        else
        {
            k++;
        }
        
    }
    printf("\n");

    return 0;
    
}