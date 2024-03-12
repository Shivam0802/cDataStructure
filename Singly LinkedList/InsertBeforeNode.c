#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int Rollno;
    struct Student *next;
};
struct Student *head;

void Display()
{
    struct Student *N;
    N = head;
    while (N != NULL)
    {
        printf("Nodes Present : ");
        printf("%d", N->Rollno);
        printf("\n");
        N = N->next;
    }
}

void InsBeg(){
    struct Student *T;
    T = (struct Student *)malloc(sizeof(struct Student));
     printf("\nEnter New Node at beginning : ");
        scanf("%d",&T -> Rollno);
        T -> next = NULL;
        T -> next = head;
        head = T;
}

void InsBeforNode()
{
    struct Student *N, *T;
    int beg;
    printf("\nEnter the Node You want to enter before : ");
    scanf("%d", &beg);
    T = (struct Student *)malloc(sizeof(struct Student));
    printf("Enter New Node : ");
    scanf("%d", &T->Rollno);
    T->next = NULL;
    N = head;
    if (head->Rollno == beg)
    {
        InsBeg();
    }
    else
    {
        while (N->next->Rollno != beg && N->next != NULL)
        {
            N = N->next;
        }
        if (N->next->Rollno == beg)
        {
            T->next = N->next;
            N->next = T;
        }
    }
}

void main()
{
    int i;
    head = NULL;
    struct Student *T, *N;
    for (i = 0; i < 3; i++)
    {
        T = (struct Student *)malloc(sizeof(struct Student));
        printf("Enter node %d :", i);
        scanf("%d", &T->Rollno);
        T->next = NULL;

        if (head == NULL)
        {
            head = T;
        }
        else
        {
            N = head;
            while (N->next != NULL)
            {
                N = N->next;
            }
            N->next = T;
        }
    }
    Display();
    InsBeforNode();
    Display();
}