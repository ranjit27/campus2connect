//Submitted for Anushka Thakurdas for review
#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
    int size;
} rq_t;

/** init ring queue */
int rq_init(rq_t *q) {
    if (!q) return -1;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    return 0;
}

/** Add value to the end of ring queue */
int rq_enqueue(rq_t *q, int value) {
    if (!q || q->size == MAX_QUEUE_LEN) return -1; // Queue full
    q->value[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->size++;
    return 0;
}

/** Remove value from front of the queue */
int rq_dequeue(rq_t *q, int *value) {
    if (!q || q->size == 0) return -1; // Queue empty
    *value = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->size--;
    return 0;
}

/** Display contents of the queue */
void rq_display(rq_t *q) {
    if (!q || q->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_QUEUE_LEN;
        printf("%d ", q->value[index]);
    }
    printf("\n");
}

// Main function with user input
int main() {
    rq_t q;
    rq_init(&q);

    int choice, val, result;

    while (1) {
        printf("\n--- Ring Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                result = rq_enqueue(&q, val);
                if (result == 0)
                    printf("Enqueued %d\n", val);
                else
                    printf("Queue is full. Cannot enqueue.\n");
                break;

            case 2:
                result = rq_dequeue(&q, &val);
                if (result == 0)
                    printf("Dequeued: %d\n", val);
                else
                    printf("Queue is empty. Cannot dequeue.\n");
                break;

            case 3:
                rq_display(&q);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
