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

void DelLast(){
    struct Student *N;
    N = head;

    if(head == NULL){
        printf("List is Empty");
    }
    else if(head -> next == NULL){
        head = NULL;
        free(N);
    }
    else{
        while(N -> next -> next != NULL){
            N = N -> next;
        }
        free(N -> next);
        N -> next = NULL;
    }
}

void main(){
    int i;
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
   Display();
   DelLast();

   printf("\nNodes After Deletion : \n");
   Display();
}


