#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct Node **root, int data)
{
    if (*root == NULL)
    {
        *root = newNode(data);
        return;
    }

    if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else
    {
        insert(&(*root)->right, data);
    }
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void sort(int arr[], int n)
{
    struct Node *root = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        insert(&root, arr[i]);
    }
    printf("\nSorted array:\n");
    inorder(root);
}

int main()
{
    int i, arr[] = {5, 3, 2, 1, 4};
    printf("Unsorted array:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);
    return 0;
}




