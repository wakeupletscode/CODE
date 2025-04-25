//4. Space complexity for bubble sorting method
void bubbleSort(int arr[], int n) 
{
    for (int i=0; i<n-1; i++) 
    {
        for (int j=0; j<n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
/*The space used by the input array is not considered because it is part of 
the problem's input rather than a space requirement of the algorithm.
The space used by the loop variables i and j and the temporary variable temp is fixed. 
Since the number of these extra variables does not increase with the size of the 
input array, we describe this space usage as constant space, denoted by O(1).
So, Space complexity= O(1)
*/
