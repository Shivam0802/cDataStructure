#include <stdio.h>
#include <stdlib.h>

int top = -1, *stack, n;

void push()
{
    int x;
    printf("Enter element: ");
    scanf("%d", &x);
    if (top <= (n - 1))
    {
        stack[++top] = x;
    }
    else
    {
        printf("Overflow");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        --top;
    }
}

void peep()
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("Element at the top %d", stack[top]);
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("\nNodes:\n");
        for (i = top; i > -1; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void main()
{
    int choice;
    printf("Enter length of Stack: ");
    scanf("%d", &n);
    stack = (int *)malloc(n * sizeof(int));
    while (1)
    {
        printf("Choose from the following:\n");
        printf("1.Push\n2.Pop\n3.Peep\n4.Display stack\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Entry");
            break;
        }
        printf("\n");
    }
}
