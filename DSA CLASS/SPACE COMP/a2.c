//2. Space complexity for fibonacci series upto n
int fibonacci(int n) 
{
    if (n<=1) 
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}
/*
when n=0 or 1,
space used is constant: O(1)= best case
worst case: for n terms
due to the nature of recursion and depth of recursion tree
space complexity: O(n)
*/
