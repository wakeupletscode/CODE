#include <stdio.h>

typedef struct 
{
    int real;
    int imag;
} Complex;

Complex addComplex(Complex a, Complex b);\
void multiplyComplex(const Complex *a, const Complex *b, Complex *result);\
void displayComplex(const Complex *c);

int main() 
{
    Complex num1, num2, result;
    int choice;
    // Input for the first complex number
    printf("Enter complex number 1 (real and imaginary parts): ");
    scanf("%d %d", &num1.real, &num1.imag);
    // Input for the second complex number
    printf("Enter complex number 2 (real and imaginary parts): ");
    scanf("%d %d", &num2.real, &num2.imag);

    while (1) {
        // Display the menu
        printf("\nMENU\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                result = addComplex(num1, num2);
                printf("Sum = %d + %di\n", result.real, result.imag);
                break;

            case 2:
                multiplyComplex(&num1, &num2, &result); 
                printf("Product = %d + %di\n", result.real, result.imag);
                break;

            default:
                printf("Invalid choice! Please enter 1 or 2.\n");
                break;
        }
    }

    return 0;
}
// Function to add two complex numbers (call by value)
Complex addComplex(Complex a, Complex b) 
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}
// Function to multiply two complex numbers (call by address)
void multiplyComplex(const Complex *a, const Complex *b, Complex *result) 
{
    result->real = a->real * b->real - a->imag * b->imag;
    result->imag = a->real * b->imag + a->imag * b->real;
}
// Function to display a complex number
void displayComplex(const Complex *c) 
{
    if (c->imag >= 0) {
        printf("%d + %di\n", c->real, c->imag);
    } else {
        printf("%d - %di\n", c->real, -c->imag);
    }
}
