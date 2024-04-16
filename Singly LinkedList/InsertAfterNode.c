#include <stdio.h>
#include <stdlib.h>

struct Student{
    int Rollno;
    struct Student *next;
};

struct Student *head;

void Display(){
    struct Student *N;
    N = head;
    while(N != NULL){
        printf("Nodes Present : ");
        printf("%d",N -> Rollno);
        printf("\n");
        N = N -> next;
    } 
}

void InsAfterNode(){
    int Aft;
    struct Student *T,*N;
    printf("Enter the node after which you want to insert : ");
    scanf("%d",&Aft);
    T = (struct Student *)malloc(sizeof(struct Student));
    printf("Enter the Node : ");
    scanf("%d",&T -> Rollno);
    T -> next = NULL;

    N = head;
    while(N -> Rollno != Aft && N != NULL){
        N = N -> next;
    }
    if(N == NULL){
        printf("Node not found");
    }
    else{
        T -> next = N -> next;
        N -> next = T;
    }
}

void main(){
    int i;
    head = NULL;
    struct Student *T,*N;
    for(i = 0 ; i < 3 ; i++){
        T = (struct Student *)malloc(sizeof(struct Student));
        printf("Enter node %d :",i );
        scanf("%d",&T -> Rollno);
        T -> next = NULL;

        if(head == NULL){
            head = T;
        }
        else {
            N=head;
            while(N -> next != NULL){
                N = N -> next;
            }
            N ->next = T;
        }
    }
   printf("\nNodes Present : \n"); 
   Display();
   InsAfterNode();
   printf("\nNodes Present after insertion : \n");
   Display();
}