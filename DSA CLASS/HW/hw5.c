/*Write a function to find the subarray with the given sum in an array of integers. For example, 
in the array [1, 4, 20, 3, 10, 5], the subarray [4, 20, 3] has the sum 27.*/
#include <stdio.h>
// Function to find the subarray with the given sum
void findSum(int arr[], int n, int tgt) 
{
    int sum=arr[0], st=0;
    for (int i = 1; i <= n; i++)
    {
        // If sum exceeds the target, remove the starting elements
        while (sum>tgt && st<i-1) 
        {
            sum -= arr[st];
            st++;
        }
        // If sum becomes equal to target, then return the subarray
        if (sum == tgt) 
        {
            printf("Subarray: ");
            for (int j = st; j <= i - 1; j++) 
            {
                printf("%d ", arr[j]);
            }
            printf("\n");
            return;
        }
        // Add this element to sum
        if (i<n) 
        {
            sum+=arr[i];
        }
    }
    printf("No subarray with the given sum found\n");
}
int main() {
    int n, tgt;
    // Take the size of the array as input
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    // Take the elements of the array as input
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    // Take the target sum as input
    printf("Enter the target sum: ");
    scanf("%d", &tgt);
    findSum(arr, n, tgt);
    return 0;
}
