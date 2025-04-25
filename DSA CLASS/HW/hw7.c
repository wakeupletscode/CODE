/*Write a function that accepts a pointer to an integer array and its size,
 then uses pointer arithmetic to reverse the array in place.*/
#include <stdio.h>
// Function to reverse the array in place using pointer arithmetic
void rev(int *arr, int sz)
{
    int *st=arr;
    int *en=arr+sz-1;
    int tmp;
    while (st<en) 
    {
        // Swap the elements at the start and end pointers
        tmp=*st;
        *st=*en;
        *en=tmp;
        // Move the pointers towards each other
        st++;
        en--;
    }
}
int main() 
{
    int sz;
    // Take the size of the array as input
    printf("Enter the size of the array: ");
    scanf("%d", &sz);
    int arr[sz];
    // Take the elements of the array as input
    printf("Enter the elements of the array:\n");
    for (int i=0; i<sz; i++) 
    {
        scanf("%d", &arr[i]);
    }
    // Print the original array
    printf("Original array: \n");
    for (int i = 0; i < sz; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Reverse the array
    rev(arr, sz);
    // Print the reversed array
    printf("Reversed array: \n");
    for (int i = 0; i < sz; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
