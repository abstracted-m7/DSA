#include <stdio.h>
#include <math.h>

//Helper function to get minimum value between "jemp size and the array size".
int min(int a, int b)
{
    return (a < b) ? a : b;
}

//Searching function
int jump_search(int arr[], int n, int target)
{

    int jump = (int)sqrt(n);//Mesure how many element will skip based on array size
    int prev = 0;

    while (arr[min(jump, n) - 1] < target)
    {
        prev = jump;
        jump += (int)sqrt(n);

        if (prev >= n)
        {
            return -1;
        }
    }

    //Perform linear search

    for (int i = prev; i < min(jump, n); i++)
    {

        if (arr[i] == target)
        {
            return i; //Return the idx of search element
        }
    }

    return -1;  
}



// Example usage
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 11;
    int result = jump_search(arr, n, target);

    if (result != -1)
    {
        printf("\nThe Element ( %d ) found at position %d.\n", target, result + 1 );
    } 
    else
    {
        printf("\nElement not found.\n");
    }

    return 0;
}
