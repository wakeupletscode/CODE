/*Create a program that intentionally causes a memory leak by allocating 
memory and not freeing it. Then modify the program to fix the memory leak 
and explain the changes made.*/
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int *ptr;
    int size;
    // Take size as input
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    // Allocate memory for 'size' integers
    ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Fill allocated memory with values
    for (int i=0; i<size; i++) 
    {
        ptr[i] = i+1;
    }
    // Print values
    printf("Array elements:\n");
    for (int i=0; i<size; i++) 
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");//no call to free so memory leaked
    return 0;
}
