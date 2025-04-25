/*Write a program to perform the following operations on a given square matrix using functions:
i. Find the no.of nonzero elements
ii. Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal
Sample Input:
Enter size of the square matrix: 4
Enter elements of the matrix:
8 2 1 0
1 0 7 6
0 6 2 4
3 9 5 0
Sample Output:
Nonzero elements : 12
Upper triangular matrix:
2 1 0
7 6
4
*/
#include <stdio.h>
void countNonZero(int matrix[][100], int size) 
{
    int count = 0;
    for (int i=0; i<size; i++) 
    {
        for (int j=0; j<size; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                count++;
            }
        }
    }
    printf("Nonzero elements: %d\n", count);
}
void displayUpperTriangular(int matrix[][100], int size)
 {
    printf("Upper triangular matrix:\n");
    for (int i=0; i<size; i++) 
    {
        for (int j=0; j<size; j++) 
        {
            if (j >= i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}
void displayAboveBelowDiagonal(int matrix[][100], int size) 
{
    printf("Elements just above and below the main diagonal:\n");
    // Above the diagonal
    printf("Above diagonal: ");
    for (int i=0; i < size - 1; i++) 
    {
        printf("%d ", matrix[i][i + 1]);
    }
    printf("\n");
    // Below the diagonal
    printf("Below diagonal: ");
    for (int i=1; i<size; i++) 
    {
        printf("%d ", matrix[i][i-1]);
    }
    printf("\n");
}
int main() 
{
    int size;
    printf("Enter size of the square matrix: ");
    scanf("%d", &size);
    if (size > 100) 
    {
        printf("Matrix size too large!\n");
        return 1;
    }
    int matrix[100][100];  // Adjusted to handle matrices up to size 100x100
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    countNonZero(matrix, size);
    displayUpperTriangular(matrix, size);
    displayAboveBelowDiagonal(matrix, size);
    return 0;
}
