#include <stdlib.h>
#include <stdio.h>

struct Polynomial
{
    int cofficient, power;
    struct Polynomial *next;
};

struct Polynomial *Head_1 = NULL, *Head_2 = NULL, *Resultant_Polynomial = NULL;

void AddPolynomial()
{
    struct Polynomial *N_1, *N_2, *N, *T;
    N_1 = Head_1;
    N_2 = Head_2;
    while (N_1 != NULL && N_2 != NULL)
    {
        T = (struct Polynomial *)malloc(sizeof(struct Polynomial));
        T->next = NULL;
        if (N_1->power > N_2->power)
        {
            T->cofficient = N_1->cofficient;
            T->power = N_1->power;
            N_1 = N_1->next;
        }
        else if (N_1->power < N_2->power)
        {
            T->cofficient = N_2->cofficient;
            T->power = N_2->power;
            N_2 = N_2->next;
        }
        else
        {
            T->cofficient = N_1->cofficient + N_2->cofficient;
            T->power = N_1->power;
            N_2 = N_2->next;
            N_1 = N_1->next;
        }
        if (Resultant_Polynomial == NULL)
            Resultant_Polynomial = T;
        else
        {
            N = Resultant_Polynomial;
            while (N->next != NULL)
            {
                N = N->next;
            }
            N->next = T;
        }
    }
    N = Resultant_Polynomial;
    while (N->next != NULL)
        N = N->next;
    if (N_2 == NULL)
    {
        N->next = N_1;
    }
    if (N_1 == NULL)
    {
        N->next = N_2;
    }
}

void Display(int i)
{
    struct Polynomial *N;
    if (i == 1)
    {
        N = Head_1;
        while (N != NULL)
        {
            printf("\n Cofficient : %d Power : %d", N->cofficient, N->power);
            N = N->next;
        }
    }
    if (i == 2)
    {
        N = Head_2;
        while (N != NULL)
        {
            printf("\n Cofficient : %d Power : %d", N->cofficient, N->power);
            N = N->next;
        }
    }
    if (i == 3)
        N = Resultant_Polynomial;
    while (N != NULL)
    {
        printf(" \n Cofficient : %d Power : %d", N->cofficient, N->power);
        N = N->next;
    }
}


void main()
{
    struct Polynomial *T, *N;
    int n_1, n_2 , i;
    printf("\n Enter Number of Terms in Polynomial 1 : ");
    scanf("%d", &n_1);
    for (int i = 1; i <= n_1; i++)
    {
        T = (struct Polynomial *)malloc(sizeof(struct Polynomial));
        printf("\n Enter Cofficient and Power :");
        scanf("%d %d", &T->cofficient, &T->power);
        T->next = NULL;
        if (Head_1 == NULL)
            Head_1 = T;
        else
        {
            N = Head_1;
            while (N->next != NULL)
                N = N->next;
            N->next = T;
        }
    }

    i = 1;
    Display(i);
    printf("\n Enter Number of Terms in Polynomial 2 : ");
    scanf("%d", &n_2);
    for (int i = 1; i <= n_2; i++)
    {
        T = (struct Polynomial *)malloc(sizeof(struct Polynomial));
        printf("\n Enter Cofficient and Power : ");
        scanf("%d %d", &T->cofficient, &T->power);
        T->next = NULL;
        if (Head_2 == NULL)
            Head_2 = T;
        else
        {
            N = Head_2;
            while (N->next != NULL)
                N = N->next;
            N->next = T;
        }
    }
    i = 2;
    Display(i);
 
    printf("\n Polynomials Added\n");
    AddPolynomial();
 
    i = 3;
    Display(i);
}



