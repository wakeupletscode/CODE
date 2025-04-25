//1. Space complexity for factorial of n
int factorial(int n) 
{
    if (n<=1)
        return 1;
    else
        return n * factorial(n - 1);
}
/*For n=0 or 1
Space: O(1): best case
For any number n, number of recursion calls =n
Space: for n*fact(n-1)= n = O(n) in worst case
Space complexity for factorial of n= O(n) */
