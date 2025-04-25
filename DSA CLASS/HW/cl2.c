//read 10 complex numbers and display them
#include <stdio.h>
#define SIZE 10
struct Com 
{
    float r; // real part
    float i; // imaginary part
};
// Function to read a complex number
void read(struct Com* c) 
{
    printf("Enter the real part: ");
    scanf("%f", &c->r);
    printf("Enter the imaginary part: ");
    scanf("%f", &c->i);
}
// Function to display a complex number
void display(struct Com c) 
{
    if (c.i >= 0)
        printf("%f + %fi\n", c.r, c.i);
    else
        printf("%f - %fi\n", c.r, -c.i);
}
int main() 
{
    struct Com n[SIZE];
    // Read 10 complex numbers
    for (int i = 0; i < SIZE; ++i) 
    {
        printf("Enter complex number %d:\n", i + 1);
        read(&n[i]);
    }
    // Display 10 complex numbers
    printf("\nThe complex numbers are:\n");
    for (int i = 0; i < SIZE; ++i) 
    {
        printf("Complex number %d: ", i + 1);
        display(n[i]);
    }
    return 0;
}
