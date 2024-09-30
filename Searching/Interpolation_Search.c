
#include<stdio.h>

int interpolation_search( int arr[], int n, int low, int high, int target)
{
   
    while (low <= high && target <= arr[high] && target >= arr[low])
    {

        if ( low == high )
        {
            if ( arr[low] == target )
            {
                return low;
            }
            
            return -1;
        }
        
        //Interpolation formula
        int prob_pos = low + (( high - low ) * ( target - arr[low] )) / ( arr[high] - arr[low]);

        // Ensure prob_pos is in array bound
        if ( prob_pos < low || prob_pos > high)
        {
            return -1;
        }
        
        //matched , increment, dicrement
        if ( arr[prob_pos] == target)
        {
           return prob_pos;
        }
        else if ( arr[prob_pos] < target)
        {
            low++;
        }
        else
        {
            high--;
        }
        
    }
    return -1;
}

int main()
{
    int arr[] = { 2, 6, 45, 78, 89, 93, 97, 111, 123, 134, 155, 167, 189};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0, high = n - 1, target = 123;

    int result = interpolation_search( arr, n, low, high, target );

    if (result != 0)
    {
        printf("\nThe element %d is found at position %d.", target, result + 1 );
    }
    else
    {
        printf("\nThe element %d is not found in the array.", target );
    }

    return 0;
}