//Program to read book details and print it
#include<stdio.h>
//Book details structure
struct Book
{
    char name[100];
    char author[100];
    char sub[100];
    char id[100];
};
//read book details
void read(struct Book* bk)
{
    printf("\nEnter Book name: ");
    scanf(" %[^\n]s", bk->name);
    printf("Enter author name: ");
    scanf(" %[^\n]s", bk->author);
    printf("Enter subject name: ");
    scanf(" %[^\n]s", bk->sub);
    printf("Enter book id: ");
    scanf(" %[^\n]s", bk->id);
}
//displays book details
void display(struct Book* bk)
{
    printf("\nBook name: %s", bk->name);
    printf("\nAuthor name: %s", bk->author);
    printf("\nSubject name: %s", bk->sub);
    printf("\nBook id: %s", bk->id);
}
int main()
{
    struct Book bk;
    read(&bk);
    display(&bk);
    return 0;
}