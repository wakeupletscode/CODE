#include<stdio.h>
#include<stdlib.h>
struct Employee
{
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra;
    float da;
    float gross_salary;
};
int main()
{
    struct Employee emp;
    int n;
    printf("Enter number of employees\n");
    scanf("%d", &n);
    
}