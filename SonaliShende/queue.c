#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct Queue{
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
}rq_t;

void init_queue(rq_t *q) {
    q->front = -1;
    q->rear = -1;
}
void enqueue(rq_t *q, int val) {
    
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    }

    q->value[q->rear] = val;
    printf("Inserted: %d\n", val);
}

void dequeue(rq_t *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int removed = q->value[q->front];
    printf("Removed: %d\n", removed);

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_LEN;
    }
}
void display(rq_t *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->value[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

int main() {
    rq_t q;
    int choice, val;

    init_queue(&q);

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);

    return 0;
}
