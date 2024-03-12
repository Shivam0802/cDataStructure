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

void DelBeg(){
    struct Student *N;
    N = head;
    if(head == NULL){
        printf("List is Empty");
    }
    else{
        head = head -> next;
        free(N);
    }
}

void DelBeforeNode(){
    struct Student *N,*T;
    N = head;
    int bef;
    printf("Enter Node before which you want to delete : ");
    scanf("%d",&bef);
    if(head == NULL){
        printf("List is Empty");
    }
    else if(head -> Rollno == bef){
        printf("No Node present before this Node");
    }
    else if(head -> next -> Rollno == bef){
        DelBeg();
    }
    else{
        while(N -> next -> next -> Rollno != bef && N -> next -> next != NULL){
            N = N -> next;
        }
        if(N -> next -> next -> Rollno == bef){
            T = N -> next;
            N -> next = T -> next;
            free(T);
        }
        else{
            printf("Node not found");
        }
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

    printf("\nNodes Before Deletion : \n");
    Display();
    DelBeforeNode();
    printf("\nNodes After Deletion : \n");
    Display();
}



