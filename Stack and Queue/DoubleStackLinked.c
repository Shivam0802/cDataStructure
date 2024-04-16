#include <stdio.h>
#include <stdlib.h>

// Structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for a double stack
typedef struct DoubleStack {
    Node* top1; // Top pointer for stack 1
    Node* top2; // Top pointer for stack 2
} DoubleStack;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if stack 1 is empty
int isStack1Empty(DoubleStack* stack) {
    return (stack->top1 == NULL);
}

// Function to check if stack 2 is empty
int isStack2Empty(DoubleStack* stack) {
    return (stack->top2 == NULL);
}

// Function to push an element to stack 1
void push1(DoubleStack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top1;
    stack->top1 = newNode;
}

// Function to push an element to stack 2
void push2(DoubleStack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top2;
    stack->top2 = newNode;
}

// Function to pop an element from stack 1
int pop1(DoubleStack* stack) {
    if (isStack1Empty(stack)) {
        printf("Stack 1 is empty!\n");
        exit(1);
    }
    Node* temp = stack->top1;
    int data = temp->data;
    stack->top1 = stack->top1->next;
    free(temp);
    return data;
}

// Function to pop an element from stack 2
int pop2(DoubleStack* stack) {
    if (isStack2Empty(stack)) {
        printf("Stack 2 is empty!\n");
        exit(1);
    }
    Node* temp = stack->top2;
    int data = temp->data;
    stack->top2 = stack->top2->next;
    free(temp);
    return data;
}

// Function to print stack 1
void printStack1(DoubleStack* stack) {
    Node* temp = stack->top1;
    printf("Stack 1: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print stack 2
void printStack2(DoubleStack* stack) {
    Node* temp = stack->top2;
    printf("Stack 2: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    DoubleStack stack;
    stack.top1 = NULL;
    stack.top2 = NULL;

    push1(&stack, 1);
    push1(&stack, 2);
    push1(&stack, 3);
    push2(&stack, 4);
    push2(&stack, 5);

    printStack1(&stack);
    printStack2(&stack);

    printf("Popped element from stack 1: %d\n", pop1(&stack));
    printf("Popped element from stack 2: %d\n", pop2(&stack));

    printStack1(&stack);
    printStack2(&stack);

    return 0;
}