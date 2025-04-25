#include <stdio.h>
void read(int r, int c, int matrix[r][c], char n) 
{
    printf("Enter elements of matrix %c (%d x %d):\n", n, r, c);
    for (int i=0; i <r; i++) 
    {
        for (int j=0; j<c; j++) 
        {
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

int main() {
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    int a[r][c], b[r][c];

    read(r, c, a, 'A');
    read(r, c, b, 'B');

    display(r, c, a, 'A');
    display(r, c, b, 'B');

    return 0;
}
