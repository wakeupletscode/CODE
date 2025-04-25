//EXAMPLE OF INDIRECT RECURSION
//Calculating factorial of a number using indirect recursion
#include <stdio.h>
// stores the factorial result
int result = 1;
// Forward declarations
void funcA(int n);
void funcB(int n);
// Function A
void funcA(int n) 
{
    if (n > 0) 
    {
        result *= n; // Multiply the result by n
        funcB(n-1); // Calls funcB with (n-1)
    }
}

// Function B
void funcB(int n) 
{
    if(n>0)
        funcA(n - 1); // Calls funcA with (n-1)
}
int main() 
{
    int num=5;
    funcA(num); //recursion
    printf("Factorial of %d: %d\n", num, result);
    return 0;
}
