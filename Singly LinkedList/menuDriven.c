#include <stdio.h>
#include <stdlib.h>
struct Student
{
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

void InsBeg(){
    struct Student *T;
    T = (struct Student *)malloc(sizeof(struct Student));
     printf("\nEnter New Node at beginning : ");
        scanf("%d",&T -> Rollno);
        T -> next = NULL;
        T -> next = head;
        head = T;
}

void Inslast(){
    struct Student *T,*N;
    T = (struct Student *)malloc(sizeof(struct Student));
        printf("\nEnter New Node at last : ");
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

void InsBeforNode()
{
    struct Student *N, *T;
    int beg;
    printf("\nEnter the Node You want to enter before : ");
    scanf("%d", &beg);
    T = (struct Student *)malloc(sizeof(struct Student));
    printf("Enter New Node : ");
    scanf("%d", &T->Rollno);
    T->next = NULL;
    N = head;
    if (head->Rollno == beg)
    {
        InsBeg();
    }
    else
    {
        while (N->next->Rollno != beg && N->next != NULL)
        {
            N = N->next;
        }
        if (N->next->Rollno == beg)
        {
            T->next = N->next;
            N->next = T;
        }
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

void sortlist(){
    struct Student *N,*T;
    int temp;
    N = head;
    while(N != NULL){
        T = N -> next;
        while(T != NULL){
            if(N -> Rollno > T -> Rollno){
                temp = N -> Rollno;
                N -> Rollno = T -> Rollno;
                T -> Rollno = temp;
            }
            T = T -> next;
        }
        N = N -> next;
    }
}

void main(){
    int i,choice;
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
    while(1){
        printf("\n");
        printf("\n1. Display");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at Last");
        printf("\n4. Insert after Node");
        printf("\n5. Insert before Node");
        printf("\n6. Delete at Beginning");
        printf("\n7. Delete at Last");
        printf("\n8. Delete after Node");
        printf("\n9. Delete before Node");
        printf("\n10. Exit");
        printf("\n Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                Display();
                break;
            case 2:
                InsBeg();
                Display();
                break;
            case 3:
                Inslast();
                Display();
                break;
            case 4:
                InsAfterNode();
                Display();
                break;
            case 5:
                InsBeforNode();
                Display();
                break;
            case 6:
                DelBeg();
                Display();
                break;
            case 7:
                DelLast();
                Display();
                break;
            case 8:
                DelAfterNode();
                Display();
                break;
            case 9:
                DelBeforeNode();
                Display();
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("Invalid Choice...!!!\nPlease Enter again : \n");
                break;
        }
    }
    sortlist();
    Display();
}



