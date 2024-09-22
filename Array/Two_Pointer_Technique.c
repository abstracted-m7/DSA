#include<stdio.h>

int main(){

    int arr[20] = {12, 15, 23, 45, 89, 93, 95, 189};
    int i, j, n = 8, target = 140;
    int left = 0, right = n - 1;

    while (left <= right) {
        int currentSum = arr[left] + arr[right];
        
        if (currentSum == target)
        {
            printf("\n\nThe left = %d and the right = %d \n\n",arr[left], arr[right]);
            break;
        }
        else if (currentSum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
                
    }
    return 0;
}