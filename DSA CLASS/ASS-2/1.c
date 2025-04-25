//Read a 2D array using dynamic memory allocation and display it
#include <stdio.h>
#include <stdlib.h>
// Function to create 2D array
int** create(int r, int c) 
{
    int **arr=(int **)malloc(r*sizeof(int *));
    for (int i=0; i<r; i++) 
    {
        arr[i]=(int *)malloc(c*sizeof(int));
    }
    return arr;
}

// Function to read 2D array
void read(int **arr, int r, int c) 
{
    printf("Enter elements of 2D array:\n");
    for (int i=0; i<r; i++) 
    {
        for (int j=0; j<c; j++) 
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
// Function to display 2D array
void display(int **arr, int r, int c) 
{
    printf("2D array:\n");
    for (int i=0; i<r; i++) 
    {
        for (int j=0; j<c; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
// Function to free allocated memory
void freeArr(int **arr, int r) 
{
    for (int i=0; i<r; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

int main() 
{
    int r,c;
    printf("Enter rows: ");
    scanf("%d", &r);
    printf("Enter cols: ");
    scanf("%d", &c);
    int **arr=create(r,c);//creates array
    read(arr, r, c);//reads array
    display(arr, r, c);//displays array
    freeArr(arr, r);//frees memory
    return 0;
}