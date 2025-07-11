#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) 
    {
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int size(Node* root) 
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() 
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Size of the binary tree: %d\n", size(root));

    return 0;
}
