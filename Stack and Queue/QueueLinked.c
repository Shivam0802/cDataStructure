#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;

void PUSH(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue is full\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = t;
        else
        {
            struct Node *p = front;
            while(p->next != NULL)
                p = p->next;
            p->next = t;
        }
    }
}

int POP()
{
    int x = -1;
    if(front == NULL)
        printf("Queue is Empty.....Underflow\n");
    else
    {
        struct Node *p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void PEEK(int pos)
{
    struct Node *p = front;
    for(int i = 0; i < pos-1 && p != NULL; i++)
        p = p->next;
    if(p != NULL)
        printf("%d\n", p->data);
    else
        printf("Invalid position\n");
}

void Display()
{
    struct Node *p = front;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void main()
{
    int n,Choice;
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
        printf("1. PUSH\n2. POP\n3. PEEK\n4. Display\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &Choice);
        switch(Choice)
        {
            case 1:
                {
                    int x;
                    printf("Enter the element: ");
                    scanf("%d", &x);
                    PUSH(x);
                    break;
                }
            case 2:
                {
                    int x = POP();
                    if(x != -1)
                        printf("Popped element: %d\n", x);
                    break;
                }
            case 3:
                {
                    int pos;
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    PEEK(pos);
                    break;
                }
            case 4:
                Display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

