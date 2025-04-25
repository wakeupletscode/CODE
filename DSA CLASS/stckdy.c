#include <stdio.h>
#include <stdlib.h>

// Global variables for the stack
int *stk;    // Pointer for dynamically allocated stack array
int top = -1; // Initialize top of stack to -1 (empty)

// Function to push an element onto the stack
void push(int val) {
    stk[++top] = val; // Increment top and push the value
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Return -1 if stack is empty
    } else {
        return stk[top--]; // Return the top element and decrement top
    }
}

int main() {
    int val, n, i;
    int *a; // Pointer for dynamically allocated array

    printf("\nEnter the array size: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the stack and the array
    stk = (int *)malloc(n * sizeof(int)); // Stack memory allocation
    if (stk == NULL) {
        printf("Memory allocation for stack failed!\n");
        return 1;
    }

    a = (int *)malloc(n * sizeof(int)); // Array memory allocation
    if (a == NULL) {
        printf("Memory allocation for array failed!\n");
        free(stk); // Free stack memory if array allocation fails
        return 1;
    }

    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Push all elements of the array onto the stack
    for (i = 0; i < n; i++) {
        push(a[i]);
    }

    // Pop elements from the stack and store back in the array
    for (i = 0; i < n; i++) {
        val = pop();
        a[i] = val;
    }

    // Print the reversed array
    printf("\nThe reversed array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    // Free the dynamically allocated memory
    free(stk);
    free(a);

    return 0; // Return success
}
