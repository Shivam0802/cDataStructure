#include <stdio.h>
#include <stdlib.h>

int *q, n, front = -1, rear = -1;

void PUSH()
{
    int x;
    printf("Enter value: ");
    scanf("%d", &x);
    if (rear == -1)
    {
        ++front;
        q[++rear] = x;
    }
    else if (rear == (n - 1))
    {
        printf("\nOverflow");
    }
    else
    {
        q[++rear] = x;
    }
}

void POP()
{
    if (front <= (n - 1))
    {
        front++;
    }
    else
    {
        printf("\nUnderflow");
    }
}

void display()
{
    int i, j;
    if (rear == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("Queue: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", q[i]);
        }
    }
}

void main()
{
    int choice;
    printf("Enter length of Queue: ");
    scanf("%d", &n);
    q = (int *)malloc(n * sizeof(int));
    while (1)
    {
        printf("\nChoose the following:\n");
        printf("1.Insert into Queue\n2.Delete from Queue\n");
        printf("3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            PUSH();
            display();
            printf("\n");
            break;
        case 2:
            POP();
            display();
            printf("\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid entry");
            break;
        }
    }
}
