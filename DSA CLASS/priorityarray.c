#include<stdio.h>
#define MAX 100
int front=-1, rear=-1;
int data[MAX], priority[MAX];
void enqueue() 
{
    int num, p;
    printf("\nEnter data: ");
    scanf("%d", &num);
    printf("\nEnter priority: ");
    scanf("%d", &p);
    if (rear == MAX-1) 
    {
        printf("\nQueue overflow");
        return;
    }
    if (front == -1 && rear == -1) 
    {
        front=rear=0;
        data[rear]=num;
        priority[rear]=p;
    } else 
    {
        int i=rear;
        while (i>=front && priority[i]> p) 
        {
            data[i+1] = data[i];
            priority[i+1] = priority[i];
            i--;
        }
        data[i+1] = num;
        priority[i+1] = p;
        rear++;
    }
}
int dequeue() 
{
    if (front == -1) 
    {
        printf("\nQueue underflow");
        return -1;
    } 
    else 
    {
        int val = data[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return val;
    }
}
int peek() 
{
    if (front == -1) 
    {
        printf("\nQueue is empty");
        return -1;
    } else
        return data[front];
}

void display() 
{
    if (front == -1)
        printf("\nQueue is empty");
    else 
    {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", data[i]);
    }
}
int main()
{
    int option, val;
    do {
        printf("\n\n**** MAIN MENU ****");
        printf("\n1. Insert an element");
        printf("\n2. Delete an element");
        printf("\n3. Peek");
        printf("\n4. Display the queue");
        printf("\n5. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option) {
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
