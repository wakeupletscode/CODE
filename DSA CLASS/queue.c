#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    int num;
    printf("\nEnter data: ");
    scanf("%d", &num);
    temp->data=num;
    temp->next=NULL;
    if(front==NULL && rear==NULL)
        front=rear=temp;
    else
    {
        rear->next=temp;
        rear=temp;
    }
}
int dequeue()
{
    struct node* temp;
    int val;
    if (front == NULL) 
    {
        printf("\nQueue underflow");
        return -1;
    } 
    else 
    {

        val = front->data;
        temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
        return val;
    }
}

int peek() 
{
    if (front == NULL)
    {
        printf("\nQueue is empty");
        return -1;
    } 
    else
        return front->data;
}
void display() 
{
    struct node* ptr;
    if (front == NULL)
        printf("\nQueue is empty");
    else 
    {
        ptr = front;
        printf("\nQueue elements: ");
        while (ptr != NULL) 
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
int main() 
{
    int option, val;
    do 
    {
        printf("\n\n**** MAIN MENU ****");
        printf("\n1. Insert an element");
        printf("\n2. Delete an element");
        printf("\n3. Peek");
        printf("\n4. Display the queue");
        printf("\n5. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option) 
        {
            case 1:
                enqueue();
                break;
            case 2:
                val = dequeue();
                if (val != -1)
                    printf("\nThe deleted element is: %d", val);
                break;
            case 3:
                val = peek();
                if (val != -1) 
                    printf("\nThe first value in the queue is: %d", val);
                break;
            case 4:
                display();
                break;
        }
    } while (option != 5);
    return 0;
}