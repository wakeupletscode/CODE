/*read 10 complex numbers and display them and return
structure pointer*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Com 
{
    float r; // real part
    float i; // imaginary part
};
// Function to read a complex number
struct Com* read() 
{
    struct Com* c=(struct Com*)malloc(sizeof(struct Com));
    if (c == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the real part: ");
    scanf("%f", &c->r);
    printf("Enter the imaginary part: ");
    scanf("%f", &c->i);
    return c;
}
// Function to display a complex number
void display(const struct Com* c) 
{
    if (c->i >= 0)
        printf("%f + %fi\n", c->r, c->i);
    else
        printf("%f - %fi\n", c->r, -c->i);
}
int main() 
{
    struct Com* n[SIZE];
    // Read 10 complex numbers
    for (int i = 0; i < SIZE; ++i) 
    {
        printf("Enter complex number %d:\n", i + 1);
        n[i] = read();
    }
    // Display 10 complex numbers
    printf("\nThe complex numbers are:\n");
    for (int i=0; i<SIZE; ++i) 
    {
        printf("Complex number %d: ", i + 1);
        display(n[i]);
    }
    // Free allocated memory
    for (int i=0; i<SIZE; ++i) 
    {
        free(n[i]);
    }
    return 0;
}
