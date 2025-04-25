/*Implement a function to create a dynamic 2D array (matrix) using pointers. 
Provide functions to fill the matrix with values, print the matrix, and free 
the allocated memory.*/
#include <stdio.h>
#include <stdlib.h>
// Function to create a dynamic 2D matrix
int** mkMat(int r, int c) 
{
    int **m=(int **)malloc(r*sizeof(int *));
    if (m==NULL) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i=0; i<r; i++) 
    {
        m[i]=(int *)malloc(c*sizeof(int));
        if (m[i]==NULL) 
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    return m;
}
// Function to fill matrix with values
void fillMat(int **m, int r, int c) 
{
    printf("Enter the elements of the matrix:\n");
    for (int i=0; i<r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}
// Function to print matrix
void prtMat(int **m, int r, int c) 
{
    printf("Matrix:\n");
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
// Function to free allocated memory
void freeMat(int **m, int r) 
{
    for (int i = 0; i < r; i++) 
    {
        free(m[i]);
    }
    free(m);
}
int main() {
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    // Create matrix
    int **m = mkMat(r, c);
    // Fill matrix with values
    fillMat(m, r, c);
    // Print the matrix
    prtMat(m, r, c);
    // Free allocated memory
    freeMat(m, r);
    return 0;
}
