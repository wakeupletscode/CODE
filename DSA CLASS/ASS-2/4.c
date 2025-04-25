//EXAMPLE OF DIRECT RECURSION
#include <stdio.h>
// Direct recursive function to calculate factorial
int factorial(int n) 
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1); // Function calls itself
}
int main() 
{
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}
