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
    DeleteBeforeNode();
    printf("\nNodes after deletion : ");
    Display();
}