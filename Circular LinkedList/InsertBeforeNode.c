#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *last = NULL;

void Display(){
    struct Node *N;
    N = last -> next;
    do{
        printf("Nodes Present : ");
        printf("%d",N -> data);
        printf("\n");
        N = N -> next;
    }while(N != last -> next);
}

void InsAfterNode(){
    struct Node *T, *P;
    int aft;
    T = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data to be inserted: ");
    scanf("%d", &T -> data);
    T -> next = NULL;
    printf("Enter the node after which the data is to be inserted: ");
    scanf("%d", &aft);
    P = last -> next;
    do{
        if (P -> data == aft){
            T -> next = P -> next;
            P -> next = T;
            if (P == last){
                last = T;
            }
            return;
        }
        P = P -> next;
    }while(P != last -> next);
    printf("Node not found\n");
}

void InsBeforeNode(){
    struct Node *T, *P;
    int bef;
    T = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data to be inserted: ");
    scanf("%d", &T -> data);
    T -> next = NULL;
    printf("Enter the node before which the data is to be inserted: ");
    scanf("%d", &bef);
    P = last -> next;
    do{
        if (P -> data == bef){
            T -> next = P -> next;
            P -> next = T;
            if (P == last){
                last = T;
            }
            return;
        }
        P = P -> next;
    }while(P != last -> next);
    printf("Node not found\n");
}

void DelBeg(){
    struct Node *P;
    P = last -> next;
    last -> next = P -> next;
    free(P);
}

void DelAfterNode(){
    struct Node *P, *Q;
    int aft;
    printf("Enter the node after which the data is to be deleted: ");
    scanf("%d", &aft);
    P = last -> next;
    do{
        if (P -> data == aft){
            Q = P -> next;
            P -> next = Q -> next;
            if (Q == last){
                last = P;
            }
            free(Q);
            return;
        }
        P = P -> next;
    }while(P != last -> next);
    printf("Node not found\n");
}



void main(){
    struct Node *T;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        T = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter node %d: ", i);
        scanf("%d", &T -> data);
        T -> next = NULL;

        if (last == NULL){
            last = T;
            T -> next = T;
        }
        else {
            T -> next = last -> next;
            last -> next = T;
            last = T;
        }
    }
    printf("\nCircular Link List\n");
    Display();

    InsBeforeNode();
    printf("\nCircular Link List after insertion\n");
    Display();
    DelBeg();
    printf("\nCircular Link List after deletion\n");
    Display();
    DelAfterNode();
    printf("\nCircular Link List after deletion\n");
    Display();
    DelBeforeNode();
    printf("\nCircular Link List after deletion\n");
    Display();
    InsAfterNode();
    printf("\nCircular Link List after insertion\n");
    Display();
    DelEnd();
    printf("\nCircular Link List after deletion\n");
    Display();
}