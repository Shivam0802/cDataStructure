#include <stdio.h>

#define size 100

int deque[size];
int f = -1, r = -1;

void insert_front(int x)
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
    {
        printf("Overflow");
    }
    else if ((f == -1) && (r == -1))
    {
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0)
    {
        f = size - 1;
        deque[f] = x;
    }
    else
    {
        f = f - 1;
        deque[f] = x;
    }
}

void insert_rear(int x)
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
    {
        printf("Overflow");
    }
    else if ((f == -1) && (r == -1))
    {
        r = 0;
        deque[r] = x;
    }
    else if (r == size - 1)
    {
        r = 0;
        deque[r] = x;
    }
    else
    {
        r++;
        deque[r] = x;
    }
}

void display()
{
    int i = f;
    printf("\nElements in a deque are: ");

    while (i != r)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % size;
    }
    printf("%d", deque[r]);
}

void getfront()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else
    {
        printf("\nThe value of the element at front is: %d", deque[f]);
    }
}

void getrear()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else
    {
        printf("\nThe value of the element at rear is %d", deque[r]);
    }
}

void delete_front()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = -1;
        r = -1;
    }
    else if (f == (size - 1))
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = 0;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = f + 1;
    }
}

void delete_rear()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[r]);
        f = -1;
        r = -1;
    }
    else if (r == 0)
    {
        printf("\nThe deleted element is %d", deque[r]);
        r = size - 1;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[r]);
        r = r - 1;
    }
}

void main()
{
    insert_front(313);
    insert_front(278);
    insert_front(233);
    printf("Deque after inserting at front: ");
    display();
    printf("\n");
    insert_rear(368);
    insert_rear(423);
    insert_rear(567);
    printf("Deque after inserting at rear: ");
    display();
    printf("\n");
    delete_front();
    delete_rear();
    printf("Deque after deleting at front and rear: ");
    display();
}
