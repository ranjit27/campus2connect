//
// Created by Anish Sapre on 10/07/25.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    struct Node* temp = *root;

    while (temp != NULL) {
        if (data < temp->data) {
            if (temp->left == NULL) {
                temp->left = createNode(data);
                return;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = createNode(data);
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}

int size(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int rightsize = size(root->right);
    int leftsize = size(root->left);
    return leftsize + rightsize + 1;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    };
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    printf("Inorder: ");
    inorderTraversal(root);
    int size_tree = size(root);
    printf("Size of BST: %d\n", size_tree);
    return 0;
}

