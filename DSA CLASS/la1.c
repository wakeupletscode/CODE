#include <stdio.h>

// Function to compare two integers pointed to by p and q
int comp(int *p, int *q) {
    if (*p > *q)
        return 0; // p is greater than q
    if (*p == *q)
        return 1; // p is equal to q
    return 2; // p is less than q
}

int main() {
    int a, b;
    
    printf("Enter 2 numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    
    int ch = comp(&a, &b);
    
    // Print comparison result based on the return value from comp
    if (ch == 0) {
        printf("%d is greater than %d\n", a, b);
    } else if (ch == 1) {
        printf("Both numbers are equal\n");
    } else if (ch == 2) {
        printf("%d is greater than %d\n", b, a);
    }
    
    return 0;
}
