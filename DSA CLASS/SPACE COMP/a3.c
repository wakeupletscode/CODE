//3.Space complexity for matrix multiplication
void multiply(int A[][n], int B[][p], int C[][p], int m, int n, int p) 
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < p; j++) 
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) 
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}
