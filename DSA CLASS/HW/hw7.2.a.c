#include <stdio.h>
#include <stdlib.h>
void readPolynomial(int **polynomial, int terms) 
{
    printf("\nEnter the polynomial:");
    for (int i = 0; i < terms; i++) 
    {
        printf("\nEnter polynomial term no. %d:\n", i + 1);
        printf("Enter coefficient: ");
        scanf("%d", &polynomial[0][i]);
        printf("Enter degree: ");
        scanf("%d", &polynomial[1][i]);
    }
}
void dividePolynomials(int **dividend, int dividendTerms, int **divisor, 
int divisorTerms, int **quotient, int **remainder, int *quotientTerms, int *remainderTerms) 
{
    int temporary[2][dividendTerms];  // Temporary array to hold intermediate steps
    // Initialize remainder to dividend
    for (int i = 0; i < dividendTerms; i++) 
    {
        remainder[0][i] = dividend[0][i];
        remainder[1][i] = dividend[1][i];
    }
    *remainderTerms = dividendTerms;
    int quotientIndex = 0;
    while (*remainderTerms > 0 && remainder[1][0] >= divisor[1][0]) {
        int coefficient = remainder[0][0] / divisor[0][0];
        int degree = remainder[1][0] - divisor[1][0];

        quotient[0][quotientIndex] = coefficient;
        quotient[1][quotientIndex] = degree;
        quotientIndex++;

        // Generate temporary array for (coefficient * divisor)
        for (int i = 0; i < divisorTerms; i++) {
            temporary[0][i] = coefficient * divisor[0][i];
            temporary[1][i] = degree + divisor[1][i];
        }

        // Subtract temporary from remainder
        int newRemainderTerms = 0;
        for (int i = 0; i < *remainderTerms; i++) {
            int found = 0;
            for (int j = 0; j < divisorTerms; j++) {
                if (remainder[1][i] == temporary[1][j]) {
                    remainder[0][i] -= temporary[0][j];
                    found = 1;
                    break;
                }
            }
            if (remainder[0][i] != 0) {
                remainder[0][newRemainderTerms] = remainder[0][i];
                remainder[1][newRemainderTerms] = remainder[1][i];
                newRemainderTerms++;
            }
        }
        *remainderTerms = newRemainderTerms;

        // Shift the remainder array to remove leading zeroes
        if (*remainderTerms > 0 && remainder[0][0] == 0) {
            for (int i = 1; i < *remainderTerms; i++) {
                remainder[0][i - 1] = remainder[0][i];
                remainder[1][i - 1] = remainder[1][i];
            }
            (*remainderTerms)--;
        }
    }

    *quotientTerms = quotientIndex;
}

int main() {
    int dividendTerms, divisorTerms;

    printf("\nEnter no. of terms in the dividend polynomial: ");
    scanf("%d", &dividendTerms);
    printf("\nEnter no. of terms in the divisor polynomial: ");
    scanf("%d", &divisorTerms);

    int **dividend = (int **)malloc(2 * sizeof(int *));
    int **divisor = (int **)malloc(2 * sizeof(int *));
    int **quotient = (int **)malloc(2 * sizeof(int *));
    int **remainder = (int **)malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++) {
        dividend[i] = (int *)malloc(dividendTerms * sizeof(int));
        divisor[i] = (int *)malloc(divisorTerms * sizeof(int));
        quotient[i] = (int *)malloc(dividendTerms * sizeof(int));  // max size is the size of dividend
        remainder[i] = (int *)malloc(dividendTerms * sizeof(int));
    }

    readPolynomial(dividend, dividendTerms);
    readPolynomial(divisor, divisorTerms);

    int quotientTerms, remainderTerms;
    dividePolynomials(dividend, dividendTerms, divisor, divisorTerms, 
    quotient, remainder, &quotientTerms, &remainderTerms);

    printf("\nQuotient: ");
    for (int i = 0; i < quotientTerms; i++) {
        if (i != 0 && quotient[0][i] > 0) {
            printf("+ ");
        }
        printf("%dx^%d ", quotient[0][i], quotient[1][i]);
    }

    printf("\nRemainder: ");
    for (int i = 0; i < remainderTerms; i++) {
        if (i != 0 && remainder[0][i] > 0) {
            printf("+ ");
        }
        printf("%dx^%d ", remainder[0][i], remainder[1][i]);
    }
    printf("\n");

    for (int i = 0; i < 2; i++) {
        free(dividend[i]);
        free(divisor[i]);
        free(quotient[i]);
        free(remainder[i]);
    }
    free(dividend);
    free(divisor);
    free(quotient);
    free(remainder);

    return 0;
}
