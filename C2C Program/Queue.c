#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
    int count;
} rq_t;

/** init ring queue */
int rq_init(rq_t *q) {
    if (!q) return -1;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return 0;
}

/** Add value to the end of ring queue */
int rq_enqueue(rq_t *q, int value) {
    if (!q || q->count == MAX_QUEUE_LEN) return -1; // Queue full or null
    q->value[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->count++;
    return 0;
}

/** remove value */
int rq_dequeue(rq_t *q, int *value) {
    if (!q || q->count == 0) return -1; // Queue empty or null
    if (value)
        *value = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->count--;
    return 0;
}

int main() {
    rq_t q;
    int choice, val;
    rq_init(&q);

    printf("FIFO Ring Queue Program (Max size = %d)\n", MAX_QUEUE_LEN);

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                if (rq_enqueue(&q, val) == 0)
                    printf("Enqueued %d successfully.\n", val);
                else
                    printf("Queue is full. Cannot enqueue.\n");
                break;

            case 2:
                if (rq_dequeue(&q, &val) == 0)
                    printf("Dequeued value: %d\n", val);
                else
                    printf("Queue is empty. Cannot dequeue.\n");
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
