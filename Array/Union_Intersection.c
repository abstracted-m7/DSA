
// Union and Intersection of two sorted array

// Input : arr1[] = {1, 3, 4, 5, 7} && arr2[] = {2, 3, 5, 6}
// Output : Union = {1, 2, 3, 4, 5, 6, 7} && Intersection : { 3, 5 }

// Time Complexity : O(n + m)
// Space Complexity : O(1)

#include<stdio.h>

int printUnion(int arr1[], int sizeArr1, int arr2[], int sizeArr2){
    int i = 0, j = 0;

    printf("Union array : ");
    while(i < sizeArr1 && j < sizeArr2)
    {
        if(arr1[i] < arr2[j])
        {
            printf("%d ", arr1[i++]);
        }
        else if(arr2[j] < arr1[i])
        {
            printf("%d ", arr2[j++]);
        }
        else //arr1[i] == arr2[j]
        {
            printf("%d ", arr1[i++]);
            j++;
        }
    }

    //Printing remaining elemnets of arr1
    while (i < sizeArr1)
    {
        printf("%d",arr1[i++]);
    }
    //Printing remaining elemnets of arr2
    while (j < sizeArr2)
    {
        printf("%d",arr2[j++]);
    }
    
    printf("\n");
}


int printIntersection(int arr1[], int sizeArr1, int arr2[], int sizeArr2){
    int i = 0, j = 0;

    printf("Intersection array : ");
    while(i < sizeArr1 && j < sizeArr2)
    {
        if(arr1[i] < arr2[j])
        {
            i++;
        }
        else if(arr2[j] < arr1[i])
        {
            j++;
        }
        else //arr1[i] == arr2[j]
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }
    printf("\n");
}

int main()
{
    int arr1[] = { 1, 3, 4, 5, 7}, arr2[] = { 2, 3, 5, 6};
    int sizeArr1 = sizeof(arr1)/sizeof(arr1[0]);
    int sizeArr2 = sizeof(arr2)/sizeof(arr2[0]);
    
    printUnion( arr1, sizeArr1, arr2, sizeArr2 );
    printIntersection( arr1, sizeArr1, arr2, sizeArr2 );

    return 0;
}