#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* top = NULL;

void push(int x) {
    struct StackNode* temp = (struct StackNode*)malloc(sizeof(struct StackNode));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int isStackEmpty() {
    return top == NULL;
}

int pop() {
    if (isStackEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    int value = top->data;
    struct StackNode* temp = top;
    top = top->next;
    free(temp);
    return value;
}

struct QueueNode {
    int data;
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

void enqueue(struct Queue* q, int value) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data = value;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        exit(1);
    }

    int value = q->front->data;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

void displayQueue(struct Queue* q) {
    struct QueueNode* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseFirstK(struct Queue* q, int k) {
    if (q == NULL || k <= 0) return;

    for (int i = 0; i < k && !isQueueEmpty(q); i++) {
        push(dequeue(q));
    }

    while (!isStackEmpty()) {
        enqueue(q, pop());
    }

    int remaining = 0;
    struct QueueNode* temp = q->front;
    while (temp != NULL) {
        remaining++;
        temp = temp->next;
    }
    remaining -= k;

    for (int i = 0; i < remaining; i++) {
        enqueue(q, dequeue(q));
    }
}

int main() {
    struct Queue* q = createQueue();

    int elements[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(elements) / sizeof(elements[0]);
    int k = 4;

    for (int i = 0; i < n; i++) {
        enqueue(q, elements[i]);
    }

    printf("Original Queue:\n");
    displayQueue(q);

    reverseFirstK(q, k);

    printf("\nQueue after reversing first %d elements:\n", k);
    displayQueue(q);

    return 0;
}