#include<stdio.h>
#include<stdlib.h>

struct Student{
    int Rollno;
    struct Student *next;
};

struct Student *head = NULL;

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

void DelAfterNode(){
    struct Student *N;
    int aft;
    printf("Enter the node after which you want to delete : ");
    scanf("%d",&aft);
    N = head;
    while(N -> Rollno != aft){
        N = N -> next;
    }
    if(N -> next == NULL){
        printf("No Node Present after this Node");
    }
    else{
        struct Student *T;
        T = N -> next;
        N -> next = T -> next;
        free(T);
    }
}

void main(){
    int i;
    struct Student *T,*N;
    for(i = 0 ; i < 5 ; i++){
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

    printf("\nBefore Deletion\n");
    Display();
    DelAfterNode();

    printf("\nAfter Deletion\n");
    Display();
}


