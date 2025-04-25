//Deduce whether a matrix is upper triangular. lower triangular or tri diagonal
#include <stdio.h>
#define MAX 100
void displayMatrix(int mat[MAX][MAX], int n) 
{
    printf("Matrix:\n");
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int isUpperTriangular(int mat[MAX][MAX], int n)
{
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<i; j++) 
        {
            if (mat[i][j] != 0) 
            {
                return 0; // Not upper triangular
            }
        }
    }
    return 1; // Upper triangular
}
int isLowerTriangular(int mat[MAX][MAX], int n) 
{
    for (int i=0; i<n; i++) 
    {
        for (int j=i+1; j<n; j++) 
        {
            if (mat[i][j] != 0)
            {
                return 0; // Not lower triangular
            }
        }
    }
    return 1; // Lower triangular
}
int isTridiagonal(int mat[MAX][MAX], int n) 
{
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            if (i != j && abs(i-j) > 1 && mat[i][j] != 0) 
            {
                return 0; // Not tridiagonal
            }
        }
    }
    return 1; // Tridiagonal
}
int main() 
{
    int mat[MAX][MAX], n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);
    printf("Enter the matrix elements:\n");
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            scanf("%d", &mat[i][j]);
        }
    }
    displayMatrix(mat, n);
    if (isUpperTriangular(mat, n)) 
    {
        printf("The matrix is upper triangular.\n");
    } 
    else if (isLowerTriangular(mat, n)) 
    {
        printf("The matrix is lower triangular.\n");
    } 
    else if (isTridiagonal(mat, n)) 
    {
        printf("The matrix is tridiagonal.\n");
    } 
    else 
    {
        printf("The matrix is neither upper triangular, lower triangular, nor tridiagonal.\n");
    }
    return 0;
}
