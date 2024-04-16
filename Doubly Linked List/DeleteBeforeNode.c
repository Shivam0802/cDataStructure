#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void Display(){
    struct Node *N;
    N = head;
    printf("\nNode present : ");
    while(N -> next != NULL){
        printf("%d ", N -> data);
        N = N -> next;
    }
    printf("%d ", N -> data);
    printf("\n");
    printf("Node present in reverse order : ");
    while(N -> prev != NULL){
        printf("%d ", N -> data);
        N = N -> prev;
    }
    printf("%d ", N -> data);
}

void InsBeg(){
    struct Node *T;
    T = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data for new node : ");
    scanf("%d", &T -> data);
    T -> next = head;
    T -> prev = NULL;
    head -> prev = T;
    head = T;
}

void InsEnd(){
    struct Node *T, *N;
    T = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data for new node : ");
    scanf("%d", &T -> data);
    T -> next = NULL;
    N = head;
    while(N -> next != NULL){
        N = N -> next;
    }
    N -> next = T;
    T -> prev = N;
}

void InsAfterNode(){
    struct Node *T, *N;
    int Aft;
    printf("\nEnter the node after which you want to insert : ");
    scanf("%d", &Aft);
    T = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data for new node : ");
    scanf("%d", &T -> data);
    N = head;
    while(N -> next != NULL && N -> data != Aft){
        N = N -> next;
    }
    if(N -> data == Aft){
        T -> next = N -> next;
        T -> prev = N;
        N -> next -> prev = T;
        N -> next = T;
    }
    else{
        printf("Node not found");
    }
}

void InsBeforeNode(){
    struct Node *T, *N;
    int Bef;
    printf("\nEnter the node before which you want to insert : ");
    scanf("%d", &Bef);
    T = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data for new node : ");
    scanf("%d", &T -> data);
    N = head;
    while(N -> next != NULL && N -> data != Bef){
        N = N -> next;
    }
    if(N -> data == Bef){
        T -> next = N;
        T -> prev = N -> prev;
        N -> prev -> next = T;
        N -> prev = T;
    }
    else{
        printf("Node not found");
    }
}

void DelEnd(){
    struct Node *D;
    D = head;
    if(head == NULL){
        printf("List is empty");
    }
    else{
        while(D -> next != NULL){
            D = D -> next;
        }
        D -> prev -> next = NULL;
        free(D);
    }
}

void DelBeg(){
    struct Node *D;
    D = head;

    if(head == NULL){
        printf("List is empty");
    }
    else {
        head = D -> next;
        head -> prev = NULL;
        free(D);
    }
}

void DeleteAfterNode(){
    struct Node *N,*D;
    int Aft;
    printf("\nEnter the node after which you want to delete : ");
    scanf("%d", &Aft);
    N = head;
    if(head == NULL){
        printf("List is empty");
    }
    else if(head -> data == Aft){
        DelEnd();
    }
    else{
        while(N -> next != NULL && N -> data != Aft){
            N = N -> next;
        }
        if(N -> data == Aft){
            D = N -> next;
            N -> next = D -> next;
            D -> next -> prev = N;
            free(D);
        }
        else{
            printf("Node not found");
        }
    }
}

void DeleteBeforeNode(){
    struct Node *N,*D,*P;
    int Bef;
    printf("\nEnter the node before which you want to delete : ");
    scanf("%d", &Bef);
    N = head;
    if(head == NULL){
        printf("List is empty");
    }
    else if(head -> data == Bef){
        printf("No node present before the given node");
    }
    else if(head -> next -> data == Bef){
        DelBeg();
    }
    else{
        while(N -> next != NULL && N -> data != Bef){
            P = N;
            N = N -> next;
        }
        if(N -> data == Bef){
            D = N -> prev;
            N -> prev = D -> prev;
            D -> prev -> next = N;
            free(D);
        }
        else{
            printf("Node not found");
        }
    }
}

void main(){
    struct Node *T, *N;
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        T = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data for node %d : ", i + 1);
        scanf("%d", &T -> data);
        T -> next = NULL;
        T -> prev = NULL;
        if(head == NULL){
            head = T;
        }
        else{
            N = head;
            while(N -> next != NULL){
                N = N -> next;
            }
            N -> next = T;
            T -> prev = N;
        }
    }
    printf("Nodes Created : ");
    Display();
    InsBeg();
    printf("\nNodes after insertion at beginning : ");
    Display();
    InsEnd();
    printf("\nNodes after insertion at end : ");
    Display();
    InsAfterNode();
    printf("\nNodes after insertion after a node : ");
    Display();
    InsBeforeNode();
    printf("\nNodes after insertion before a node : ");
    Display();
    DelEnd();
    printf("\nNodes after deletion at end : ");
    Display();
    DelBeg();
    printf("\nNodes after deletion at beginning : ");
    Display();
    DeleteAfterNode();
    printf("\nNodes after deletion : ");
    Display();
    DeleteBeforeNode();
    printf("\nNodes after deletion : ");
    Display();
}