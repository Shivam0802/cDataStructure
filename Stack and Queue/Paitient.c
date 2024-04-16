#include <stdio.h>
#include <stdlib.h>

struct QHospital
{
    int pid, coupon;
    struct QHospital *link1;
};

struct QHospital *start1 = NULL;

struct SHospital
{
    int pid;
    struct SHospital *link2;
};

struct SHospital *start2 = NULL;
int temp;

void displayQueue()
{
    struct QHospital *n;
    n = start1;
    printf("Nodes:\n");
    while (n != NULL)
    {
        printf("%d\t%d\n", n->coupon, n->pid);
        n = n->link1;
    }
}

void displayStack()
{
    struct SHospital *n;
    n = start2;
    printf("Nodes:\n");
    while (n != NULL)
    {
        printf("%d\n", n->pid);
        n = n->link2;
    }
}

void inslastQueue()
{
    struct QHospital *t, *n;
    t = (struct QHospital *)malloc(sizeof(struct QHospital));
    printf("Enter a Coupon number:");
    scanf("%d", &t->coupon);
    printf("Enter a Patient ID:");
    scanf("%d", &t->pid);
    t->link1 = NULL;
    if (start1 == NULL)
    {
        start1 = t;
    }
    else
    {
        n = start1;
        while (n->link1 != NULL)
        {
            n = n->link1;
        }
        n->link1 = t;
    }
}

void insbegStack()
{
    struct SHospital *t;
    t = (struct SHospital *)malloc(sizeof(struct SHospital));
    t->pid = temp;
    t->link2 = NULL;
    t->link2 = start2;
    start2 = t;
}

void delbegStack()
{
    struct SHospital *d;
    d = start2;
    start2 = start2->link2;
    free(d);
}

void delbegQueue()
{
    struct QHospital *d;
    d = start1;
    temp = start1->pid;
    insbegStack();
    start1 = start1->link1;
    free(d);
}

void main()
{
    int i = 1, j;
    while (i == 1)
    {
        printf("\nChoose from the following:\n");
        printf("1.Insert in Queue\n2.Delete from Queue\n3.Display Queue");
        printf("\n4.Delete from Stack\n5.Display Stack\n");
        scanf("%d", &j);
        switch (j)
        {
        case 1:
            inslastQueue();
            break;
        case 2:
            delbegQueue();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            delbegStack();
            break;
        case 5:
            displayStack();
            break;
        default:
            printf("Invalid entry");
            break;
        }
        printf("\nPress 1 to continue or any other to exit\n");
        scanf("%d", &i);
    }
}
