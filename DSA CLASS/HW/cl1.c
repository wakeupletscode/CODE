//Program to read,add,multiply 2 complex numbers and return structure pointer
#include <stdio.h>
#include <stdlib.h>
struct Complex 
{
    float r; // real part
    float i; // imaginary part
};
// Function to read complex number
struct Complex rc() 
{
    struct Complex c;
    printf("Enter the real part: ");
    scanf("%f", &c.r);
    printf("Enter the imaginary part: ");
    scanf("%f", &c.i);
    return c;
}
// Function to display complex number
void display(struct Complex* c) 
{
    if (c->i >= 0)
        printf("%f + %fi\n", c->r, c->i);
    else
        printf("%f - %fi\n", c->r, -c->i);
}
// Function to add two complex numbers and return a pointer to the result
struct Complex* add(struct Complex* c1, struct Complex* c2) 
{
    struct Complex* result=(struct Complex*)malloc(sizeof(struct Complex));
    if (result != NULL)
    {
        result->r = c1->r + c2->r;
        result->i = c1->i + c2->i;
    }
    return result;
}
// Function to multiply two complex numbers and return a pointer to the result
struct Complex* multiply(struct Complex* c1, struct Complex* c2) 
{
    struct Complex* result = (struct Complex*)malloc(sizeof(struct Complex));
    if (result != NULL) 
    {
        result->r = c1->r * c2->r - c1->i * c2->i;
        result->i = c1->r * c2->i + c1->i * c2->r;
    }
    return result;
}
int main() 
{
    struct Complex c1, c2;
    struct Complex *sum, *product;
    printf("Enter the 1st complex number:\n");
    c1 = rc();
    printf("Enter the 2nd complex number:\n");
    c2 = rc();
    sum = add(&c1, &c2);
    product = multiply(&c1, &c2);
    printf("First complex number: ");
    display(&c1);
    printf("Second complex number: ");
    display(&c2);
    printf("Sum of the two complex numbers: ");
    display(sum);
    printf("Product of the two complex numbers: ");
    display(product);
    // Free the allocated memory
    free(sum);
    free(product);
    return 0;
}
