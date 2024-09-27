
#include<stdio.h>
int main()
{
    int arr[] = { 1, 6, 2, 8, 4, 9, 15, 45, 87, 89};
    int i, size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    for ( i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            printf("The element %d found at position %d.",arr[i],i+1);
            break;
        }
        
    }
    return 0;    
}