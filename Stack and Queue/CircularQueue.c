#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, n, *queue;

int checkFull()
{
  if ((front == rear + 1) || (front == 0 && rear == n - 1))
  {
    return 1;
  }
  return 0;
}

int checkEmpty()
{
  if (front == -1)
  {
    return 1;
  }
  return 0;
}

void enqueue(int value)
{
  if (checkFull())
  {
    printf("Overflow\n");
  }
  else
  {
    if (front == -1)
    {
      front = 0;
    }
    rear = (rear + 1) % n;
    queue[rear] = value;
  }
}

int dequeue()
{
  int variable;
  if (checkEmpty())
  {
    printf("Underflow condition\n");
    return -1;
  }
  else
  {
    variable = queue[front];
    if (front == rear)
    {
      front = rear = -1;
    }
    else
    {
      front = (front + 1) % n;
    }
    return 1;
  }
}

void print()
{
  int i;
  if (checkEmpty())
    printf("Nothing to dequeue\n");
  else
  {
    printf("\nQueue:\n");
    for (i = front; i != rear; i = (i + 1) % n)
    {
      printf("%d\t", queue[i]);
    }
    printf("%d\t", queue[i]);
  }
}

void main()
{
  printf("Enter length of Queue: ");
  scanf("%d", &n);
  queue = (int *)malloc(n * sizeof(int));
  int choice, x, y;
  while (1)
  {
    printf("\nChoose from the following: ");
    printf("\n1.Insert\n2.Delete\n3.Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter a value: ");
      scanf("%d", &x);
      enqueue(x);
      print();
      break;
    case 2:
      y = dequeue();
      print();
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("Invalid Entry");
      break;
    }
  }
}
