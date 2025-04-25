/*Addition, Multiplication of 3 complex numbers numbers
using structures*/
#include <stdio.h>
struct Com {
    float r; // real part
    float i; // imaginary part
};
// Function to read a complex number
struct Com rc() 
{
    struct Com c;
    printf("Enter the real part: ");
    scanf("%f", &c.r);
    printf("Enter the imaginary part: ");
    scanf("%f", &c.i);
    return c;
}
// Function to display a complex number
void display(struct Com c) 
{
    if (c.i >= 0)
        printf("%f + %fi\n", c.r, c.i);
    else
        printf("%f - %fi\n", c.r, -c.i);
}
// Function to add three complex numbers
void add(struct Com c1, struct Com c2, struct Com c3, struct Com* result) 
{
    result->r=c1.r+c2.r+c3.r;
    result->i=c1.i+c2.i+c3.i;
}
// Function to multiply three complex numbers
void multiply(struct Com c1, struct Com c2, struct Com c3, struct Com* result) 
{
    struct Com temp; // Multiply c1 and c2 first
    temp.r = c1.r*c2.r-c1.i*c2.i;
    temp.i = c1.r*c2.i+ c1.i*c2.r;// Then multiply the result with c3
    result->r=temp.r*c3.r-temp.i*c3.i;
    result->i=temp.r*c3.i+temp.i*c3.r;
}
int main() 
{
    struct Com c1, c2, c3, sum, product;
    printf("Enter the 1st complex number:\n");
    c1 = rc();
    printf("Enter the 2nd complex number:\n");
    c2 = rc();
    printf("Enter the 3rd complex number:\n");
    c3 = rc();
    add(c1, c2, c3, &sum);
    multiply(c1, c2, c3, &product);
    printf("First complex number: ");
    display(c1);
    printf("Second complex number: ");
    display(c2);
    printf("Third complex number: ");
    display(c3);
    printf("Sum of the three complex numbers: ");
    display(sum);
    printf("Product of the three complex numbers: ");
    display(product);
    return 0;
}