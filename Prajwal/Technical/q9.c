#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* treeNode) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return node;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

int countHalfNodes(struct Node* root) {
    if (root == NULL) return 0;
    struct Queue* q = createQueue();
    enqueue(q, root);
    int count = 0;

    while (!isQueueEmpty(q)) {
        struct Node* current = dequeue(q);
        int hasLeft = current->left != NULL;
        int hasRight = current->right != NULL;

        if ((hasLeft && !hasRight) || (!hasLeft && hasRight))
            count++;

        if (hasLeft)
            enqueue(q, current->left);
        if (hasRight)
            enqueue(q, current->right);
    }

    free(q);
    return count;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    root->right->right->left = createNode(7);

    int halfNodes = countHalfNodes(root);
    printf("Number of half nodes: %d\n", halfNodes);

    return 0;
}