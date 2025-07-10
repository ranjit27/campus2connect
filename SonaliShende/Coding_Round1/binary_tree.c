#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* queue[MAX];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == MAX - 1) return;
    queue[++rear] = node;
    if (front == -1) front = 0;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root, int val) {
    struct Node* newNode = createNode(val);

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    front = rear = -1;  
    enqueue(*root);

    while (!isEmpty()) {
        struct Node* temp = dequeue();

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            enqueue(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            enqueue(temp->right);
        }
    }
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        insert(&root, val);
    }

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
