//Multiply 2 sparse matrices in sparse form
#include <stdio.h>
#define MAX 100
void convertToSparse(int matrix[MAX][MAX], int r, int c, int s[MAX][3]) 
{
    int k=1;
    s[0][0]=r;
    s[0][1]=c;
    s[0][2]=0; 
    for (int i=0; i<r; i++) 
    {
        for (int j=0; j<c; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = matrix[i][j];
                k++;
                s[0][2]++;
            }
        }
    }
}
void create(int s[MAX][3], int r) 
{
    printf("Enter number of non-zero elements: ");
    scanf("%d", &s[0][2]);
    printf("Enter the row, column, and value:\n");
    for (int i=1; i<=s[0][2]; i++) 
    {
        scanf("%d%d%d", &s[i][0], &s[i][1], &s[i][2]);
    }
    s[0][0] = r;
    s[0][1] = r;
}
void multiply(int s1[MAX][3], int s2[MAX][3], int result[MAX][3]) 
{
    if (s1[0][1] != s2[0][0]) 
    {
        printf("Matrix multiplication not possible\n");
        return;
    }
    int k=1;
    result[0][0] = s1[0][0];
    result[0][1] = s2[0][1];
    result[0][2] = 0;
    for (int i=1; i<=s1[0][2]; i++) 
    {
        for (int j=1; j<=s2[0][2]; j++) 
        {
            if (s1[i][1] == s2[j][0]) 
            {  
                int row = s1[i][0];
                int col = s2[j][1];
                int value = s1[i][2] * s2[j][2];
                int found = 0;
                for (int l=1; l<k; l++) 
                {
                    if (result[l][0] == row && result[l][1] == col) 
                    {
                        result[l][2] += value;
                        found = 1;
                        break;
                    }
                }
                if (!found) 
                {
                    result[k][0] = row;
                    result[k][1] = col;
                    result[k][2] = value;
                    k++;
                }
            }
        }
    }
    result[0][2] = k-1;
}
void display(int s[MAX][3]) 
{
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= s[0][2]; i++) 
    {
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
    }
}
int main() 
{
    int r1, c1, r2, c2;
    int matrix1[MAX][MAX], matrix2[MAX][MAX];
    int s1[MAX][3], s2[MAX][3], result[MAX][3];
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter elements of the first matrix:\n");
    for (int i=0; i<r1; i++) 
    {
        for (int j=0; j<c1; j++) 
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d%d", &r2, &c2);
    printf("Enter elements of the second matrix:\n");
    for (int i=0; i<r2; i++) 
    {
        for (int j=0; j<c2; j++) 
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    convertToSparse(matrix1, r1, c1, s1);
    convertToSparse(matrix2, r2, c2, s2);
    printf("Sparse Matrix 1:\n");
    display(s1);
    printf("Sparse Matrix 2:\n");
    display(s2);
    multiply(s1, s2, result);
    printf("Resultant Sparse Matrix after Multiplication:\n");
    display(result);
    return 0;
}
