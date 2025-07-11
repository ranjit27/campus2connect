#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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


typedef struct Queue 
{
    Node* arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) 
{
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) 
{
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) 
{
    if (q->rear < MAX) 
    {
        q->arr[q->rear++] = node;
    }
}

Node* dequeue(Queue* q) 
{
    if (!isEmpty(q)) 
    {
        return q->arr[q->front++];
    }
    return NULL;
}

Node* insert(Node* root, int data) 
{
    Node* newNode = createNode(data);

    if (root == NULL)
        return newNode;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) 
    {
        Node* temp = dequeue(&q);

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else {
            enqueue(&q, temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else {
            enqueue(&q, temp->right);
        }
    }

    return root;
}

void inorder(Node* root) 
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    printf("Inorder Traversal of Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
