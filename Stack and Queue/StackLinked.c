#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void PUSH(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int POP()
{
    struct Node *t;
    int x = -1;
    if(top == NULL)
        printf("Stack is Empty....Underflow\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void PEEK(int pos)
{
    struct Node *p = top;
    for(int i = 0; i < pos-1 && p != NULL; i++)
        p = p->next;
    if(p != NULL)
        printf("%d\n", p->data);
    else
        printf("Invalid position\n");
}

void Display()
{
    struct Node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void main()
{
    int n,choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        printf("Enter the element: ");
        scanf("%d", &x);
        PUSH(x);
    }
    while(1)
    {
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.Display\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element: ");
                scanf("%d", &n);
                PUSH(n);
                break;
            case 2:
                n = POP();
                if(n != -1)
                    printf("Popped element is %d\n", n);
                printf("\n");
                break;
            case 3:
                printf("\nEnter the position: ");
                scanf("%d", &n);
                PEEK(n);
                break;
            case 4:
                Display();
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

