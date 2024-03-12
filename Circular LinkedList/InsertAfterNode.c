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
}