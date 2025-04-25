/*Given two sorted arrays, write a function to merge them 
into a single sorted array without using any extra space (merge in-place)*/
#include <stdio.h>
// Function to merge 2 sorted arrays into one
void mergeInPlace(int arr1[], int n1, int arr2[], int n2) 
{
    int i = 0, j = 0, k = 0;
    // Traverse the 2 arrays
    while (i<n1 && j<n2)
    {
        if (arr1[i]<=arr2[j])
        {
            i++;
        } 
        else 
        {
            // Shift all elements in arr1 to the right by 1
            int temp=arr2[j];
            for (k=n1-1; k>=i; k--) 
            {
                arr1[k+1] = arr1[k];
            }
            arr1[i]=temp;
            i++;
            n1++;
            j++;
        }
    }
    // Copy remaining elements of arr2[]
    while (j<n2) 
    {
        arr1[i++] = arr2[j++];
    }
}
int main() 
{
    int arr1[100] = {1, 3, 5, 7}; 
    int n1=4; // Number of elements in arr1
    int arr2[]={2, 4, 6, 8};
    int n2 = sizeof(arr2)/sizeof(arr2[0]); // Number of elements in arr2
    // Print original arrays
    printf("Original array 1: \n");
    for (int i=0; i<n1; i++) 
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Original array 2: \n");
    for (int i = 0; i<n2; i++) 
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    mergeInPlace(arr1, n1, arr2, n2);
    // Print the merged array
    printf("Merged array: \n");
    for (int i=0; i<n1+n2; i++) 
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    return 0;
}
