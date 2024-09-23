// Count number of occurrences( or frequency) in sorted array.
// Input : N = 7, X = 2, Arr[] = {1, 1, 2, 2, 2, 2, 3}
// Output : 4
// Explanation: 2 occurs 4 times in the array.

// Input : N = 7, X = 4, Arr[] = {1, 1, 2, 2, 2, 2, 3}
// Output : 0
// Explanation: 4 is not in the array.


//Solve in linear search. --> TC : O(n) & SC : O(1)

#include<stdio.h>

int main()
{
    int arr[] = {1, 2, 2, 5, 5, 5, 5, 5, 5, 7, 8, 11, 11, 11};
    int i, size = sizeof(arr)/sizeof(arr[0]);

    int target_num = 5, count = 0;

    for ( i = 0; i < size; i++)
    {
        if (arr[i] == target_num)
        {
            count++;
        }
        
    }
    printf("\nThe %d ocurrs %d times in this array.", target_num, count);
    return 0;
}