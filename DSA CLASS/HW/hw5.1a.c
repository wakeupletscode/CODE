//Program to add 2 sparse matrices in sparse form
#include <stdio.h>
struct sparse 
{
    int r, c;
    int value;
};
void read(int r, int c, int matrix[r][c], char n) 
{
    printf("Enter elements of matrix %c (%d x %d):\n", n, r, c);
    for (int i=0; i<r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void display(int r, int c, int matrix[r][c], char n) 
{
    printf("Matrix %c (%d x %d):\n", n, r, c);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int creates(int r, int c, int matrix[r][c], struct sparse s[])//creates sparse matrix
{
    int k=0;
    for (int i=0; i<r; i++) 
    {
        for (int j=0; j<c; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                s[k].r = i;
                s[k].c = j;
                s[k].value = matrix[i][j];
                k++;
            }
        }
    }
    return k; // Returns the count of non-zero elements
}
void adds(struct sparse sA[], int cA, struct sparse sB[], int cB, struct sparse result[], int *cR) 
{
    int i = 0, j = 0, k = 0;
    while (i < cA && j < cB) 
    {
        if (sA[i].r < sB[j].r || (sA[i].r == sB[j].r && sA[i].c < sB[j].c)) 
        {
            result[k++] = sA[i++];
        }
         else if (sB[j].r < sA[i].r || (sB[j].r == sA[i].r && sB[j].c < sA[i].c)) 
        {
            result[k++] = sB[j++];
        } 
        else 
        {
            result[k].r = sA[i].r;
            result[k].c = sA[i].c;
            result[k].value = sA[i].value + sB[j].value;
            k++;
            i++;
            j++;
        }
    }
    while (i<cA) 
    {
        result[k++] = sA[i++];
    }

    while (j<cB) 
    {
        result[k++] = sB[j++];
    }
    *cR = k;
}
void displays(struct sparse s[], int c, char n) 
{
    printf("Sparse Matrix %c (in triplet form):\n", n);
    printf("Row Col Value\n");
    for (int i=0; i<c; i++) 
    {
        printf("%d   %d   %d\n", s[i].r, s[i].c, s[i].value);
    }
}
int main() 
{
    int r, c;
    printf("Enter the no. of rows: ");
    scanf("%d", &r);
    printf("Enter the no. of columns: ");
    scanf("%d", &c);
    int a[r][c], b[r][c];
    read(r, c, a, 'A');
    read(r, c, b, 'B');
    struct sparse sA[r * c], sB[r * c], result[r * c];
    int cA, cB, cR;
    cA = creates(r, c, a, sA);
    cB = creates(r, c, b, sB);
    adds(sA, cA, sB, cB, result, &cR);
    printf("\n");
    displays(sA, cA, 'A');
    printf("\n");
    displays(sB, cB, 'B');
    printf("\n");
    displays(result, cR, 'R');
    return 0;
}
