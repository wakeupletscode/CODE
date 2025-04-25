#include <stdio.h>

// Define the structure to store employee information
typedef struct {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
    float gross_salary;
} Employee;

// Function prototypes
void inputEmployeeInfo(Employee *emp, int id);
void displayEmployeeInfo(const Employee *emp);

int main() {
    int n;

    // Input number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Declare an array of Employee structures
    Employee employees[n];

    // Input information for each employee
    for (int i = 0; i < n; i++) {
        printf("\nEnter employee %d information:\n", i + 1);
        inputEmployeeInfo(&employees[i], i + 1);
    }

    // Display employee information
    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        displayEmployeeInfo(&employees[i]);
    }

    return 0;
}

// Function to input employee information
void inputEmployeeInfo(Employee *emp, int id) {
    emp->emp_id = id;
    printf("Name: ");
    scanf("%s", emp->name);
    printf("Designation: ");
    scanf("%s", emp->designation);
    printf("Basic Salary: ");
    scanf("%f", &emp->basic_salary);
    printf("HRA %%: ");
    scanf("%f", &emp->hra_percent);
    printf("DA %%: ");
    scanf("%f", &emp->da_percent);

    // Calculate gross salary
    emp->gross_salary = emp->basic_salary + 
                        (emp->basic_salary * emp->hra_percent / 100) + 
                        (emp->basic_salary * emp->da_percent / 100);
}

// Function to display employee information
void displayEmployeeInfo(const Employee *emp) {
    printf("Name: %s\n", emp->name);
    printf("Designation: %s\n", emp->designation);
    printf("Basic Salary: %.2f\n", emp->basic_salary);
    printf("HRA %%: %.2f%%\n", emp->hra_percent);
    printf("DA %%: %.2f%%\n", emp->da_percent);
    printf("Gross Salary: %.2f\n\n", emp->gross_salary);
}
