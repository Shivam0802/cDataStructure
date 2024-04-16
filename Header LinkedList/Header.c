#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Header
{
    int count;
    struct Node *head;
};

struct Header *header = NULL;

void insert()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = header->head;
    header->head = newNode;
    header->count++;
}

void delete()
{
    struct Node *temp = header->head;
    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
    {
        if (prev == NULL)
        {
            header->head = header->head->next;
        }
        else
        {
            prev->next = temp->next;
        }
        free(temp);
        header->count--;
    }
}

void display()
{
    struct Node *temp = header->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    printf("Number of elements: %d\n", header->count);
}

void main()
{
    header = (struct Header *)malloc(sizeof(struct Header));
    header->count = 0;
    header->head = NULL;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        insert();
    }
    display();
    delete ();
    display();
}