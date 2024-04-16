#include <stdio.h>
#include <stdlib.h>

int stk[10];
int top_1 = -1, top_2 = 10;

void push_1()
{
    if ((top_1 + 1) == top_2)
        printf("Overflow");
    else
    {
        printf("Enter the Value in 1st Stack: ");
        top_1++;
        scanf("%d", &stk[top_1]);
    }
}

void push_2()
{
    if ((top_1 + 1) == top_2)
        printf("Overflow");
    else
    {
        top_2--;
        printf("Enter the Value for 2nd Stack: ");
        scanf("%d", &stk[top_2]);
    }
}

void pop_1()
{
    if (top_1 == -1)
        printf("Underflow");
    else
    {
        printf("\nValue being deleted from 1st Stack is %d", stk[top_1--]);
    }
}

void pop_2()
{
    if (top_2 == 10)
        printf("Underflow");
    else
    {
        printf("\nThe value being deleted from 2nd Stack is %d", stk[top_2++]);
    }
}

void display()
{
    int i;
    printf("\nStack 1: ");
    for (i = 0; i <= top_1; i++)
    {
        printf("%d\t", stk[i]);
    }
    printf("\nStack 2: ");
    for (i = 9; i >= top_2; i--)
    {
        printf("%d\t", stk[i]);
    }
}

void main()
{
    push_1();
    push_1();
    push_1();
    printf("\n");
    push_2();
    push_2();
    push_2();
    display();
    printf("\n");
    pop_2();
    pop_1();
    printf("\n");
    display();
}
