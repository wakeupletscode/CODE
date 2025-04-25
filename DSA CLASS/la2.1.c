/*WAP to create a 1-D array of n elements and perform the following menu based operations using
function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array
Sample Input/Output:
Enter size n : 5
Enter element of array:
Enter Array elements: 10 23 45 37 52
***MENU***
1. Insert
2. Delete
3. Linear Search
4. Traverse
Example
Enter option: 1
Element to insert: 61 Enter Position: 2
Element inserted
Enter option: 4
Array Elements: 10 23 61 45 37 52*/
#include<stdio.h>
#include<stdlib.h>
void create(int n, int *arr)
{
    printf("Enter %d elements\n", n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display(int n, int *arr)
{
    printf("Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d, ", arr[i]);
    }
}
void insert(int *n, int **arr, int pos, int x)
{
    *arr=realloc(*arr,(*n+1) * sizeof(int));
    if (*arr == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    for (int i=*n; i>pos; i--)
    {
        (*arr)[i] = (*arr)[i-1];
    }
    (*arr)[pos] = x;
    (*n)++;
}
void delete(int *n, int **arr, int pos)
{
    if(pos<0 || pos>*n)
    {
        printf("Invalid position\n");
        return;
    }
    else
    {
        for(int i=pos; i<*n-1; i++)
        {
            arr[i]=arr[i+1];
        }
        (*n)--;
        *arr=realloc(*n,(*n)*sizeof(int));
        if(*n>0 && arr==NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
    }
}
void search(int *n, int **arr, int flag)
{
    for(int i=0;i<n;i++)
    {
        if(flag==arr[i]);
        {   
            printf("\nElement found at position: %d",i);
            return;
        }
    }
    printf("\nElement not found");
}
int menu(int *n, int **arr)
{
    int ch;
    printf("\n-----MENU-----\n");
    printf("1. Insert\n2. Delete\n3. Linear Search\n4. Traverse\n");
    printf("Enter choice: ");
    scanf("%d", ch);
    switch(ch)
    {
        case 1:
        {
            //insertion
            int x,pos;
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &x);
            printf("\nEnter the position at which the element is to be entered: ");
            scanf("%d", &pos);
            insert(n, arr, pos, x);
            break;
        }
        case 2:
        {
            //deletion
            int pos;
            printf("\nEnter position of element to be deleted: ");
            scanf("%d", &pos);
            delete(n, *arr, pos);
            break;
        }
        case 3:
        {
            //linear search
            int flag;
            printf("\nEnter the element to be searched: ");
            scanf("%d", &flag);
            search(n, arr, flag);
            break;
        }
        case 4:
        {
            //traverse
            display(n, arr);
            break;
        }
        default:
        {
            printf("\nCHOICE INAVLID\n");
            break;
        }
    }
}
int main()
{   
    int n;
    printf("\nEnter the number of elecments: ");
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    create(n,arr);
    menu(&n, &arr);
}