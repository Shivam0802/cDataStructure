#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int top1 = -1, top2 = -1, *stack1, *stack2;

void pushPost(int item)
{
    if (top1 == sizeof(stack1) / sizeof(int))
    {
        printf("Overflow");
    }
    else
    {
        stack1[++top1] = item;
    }
}

int popPost()
{
    if (top1 == -1)
    {
        printf("Underflow");
    }
    else
    {
        return stack1[top1--];
    }
}

void pushPre(int item)
{
    if (top2 == sizeof(stack2) / 2)
    {
        printf("Overflow");
    }
    else
    {
        stack2[++top2] = item;
    }
}

int popPre()
{
    if (top2 == -1)
    {
        printf("Underflow");
    }
    else
    {
        return stack2[top2--];
    }
}

int evaluatePostfix(char *e)
{
    int i, x, op1, op2, result;
    char symbol;
    for (i = 0; e[i] != '\0'; i++)
    {
        symbol = e[i];
        if (isdigit(symbol))
        {
            pushPost(symbol - '0');
        }
        else
        {
            op2 = popPost();
            op1 = popPost();
            switch (symbol)
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '^':
                result = pow(op1, op2);
                break;
            }
            pushPost(result);
        }
    }
    x = popPost();
    return x;
}

int evaluatePrefix(char *e)
{
    int i, len, x, op1, op2, result;
    len = strlen(e);
    for (i = len - 1; i >= 0; i--)
    {
        if (isdigit(e[i]))
        {
            pushPre(e[i] - '0');
        }
        else
        {
            op1 = popPre();
            op2 = popPre();
            switch (e[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 + op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            }
            pushPre(result);
        }
    }
    x = popPre();
    return x;
}

void main()
{
    int choice, r;
    char s[100];

    while (1)
    {
        printf("\nChoose from the following:\n");
        printf("1.Evaluate Postfix Expression\n2.Evaluate Prefix Expression\n3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Postfix expression: ");
            scanf("%s", s);
            stack1 = (int *)malloc(strlen(s) * sizeof(int));
            r = evaluatePostfix(s);
            printf("Result: %d\n", r);
            break;
        case 2:
            printf("Enter Prefix expression: ");
            scanf("%s", s);
            stack2 = (int *)malloc(strlen(s) * sizeof(int));
            r = evaluatePrefix(s);
            printf("Result: %d\n", r);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}
