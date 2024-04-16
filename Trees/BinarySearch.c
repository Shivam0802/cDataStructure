#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

// Function to create a new node
void InsertNode(){
    struct Node *N,*T,*Prev; 
    N = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d",&N->data);
    N->left = NULL;
    N->right = NULL;
    if(root == NULL){
        root = N;
    }
    else{
        T = root;
        while(T != NULL){
            if(N->data < T->data){
                Prev = T;
                T = T->left;
            }
            else{
                Prev = T;
                T = T->right;
            }
        }
        if(N->data < Prev->data){
            Prev->left = N;
        }
        else{
            Prev->right= N;
        }
    }
}

// Function to traverse the binary search tree in inorder and store the sorted elements in the array
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to sort the array using a binary search tree
// void sortArrayUsingBST(int* arr, int n) {
//     struct Node* root = NULL;

//     // Insert elements into the binary search tree
//     for (int i = 0; i < n; i++) {
//         root = insertNode(root, arr[i]);
//     }

//     // Traverse the binary search tree in inorder and store the sorted elements in the array
//     int index = 0;
//     inorderTraversal(root, arr, &index);
// }

void Display(){
    struct Node *T;
    T = root;
    if(T == NULL){
        printf("Tree is empty\n");
    }
    else{
        printf("Inorder Traversal: ");
        inorderTraversal(T);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Original BST: ");
    for (int i = 0; i < n; i++) {
        InsertNode();
    }

    printf("Inorder Traversal BST: ");
    Display();

    return 0;
}