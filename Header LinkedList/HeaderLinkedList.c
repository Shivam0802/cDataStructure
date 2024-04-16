#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;

void insert(){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void delete(){
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void display(){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main(){
    struct Npde *T;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        insert();
    }
    display();
    delete();
    display();
}
