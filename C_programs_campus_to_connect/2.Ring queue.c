#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int head;
    int tail;
    int count;
} rq_t;

int rq_init(rq_t *q) {
    if (q == NULL) return -1;
    q->head = 0;
    q->tail = 0;
    q->count = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int value) {
    if (q == NULL || q->count >= MAX_QUEUE_LEN) return -1;
    q->value[q->tail] = value;
    q->tail = (q->tail + 1) % MAX_QUEUE_LEN;
    q->count++;
    return 0;
}

int rq_dequeue(rq_t *q, int *value) {
    if (q == NULL || value == NULL || q->count <= 0) return -1;
    *value = q->value[q->head];
    q->head = (q->head + 1) % MAX_QUEUE_LEN;
    q->count--;
    return 0;
}

int main() {
    rq_t queue;
    int value, choice;
    rq_init(&queue);

    while (1) {
        printf("\n----- Ring Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            if (rq_enqueue(&queue, value) == 0)
                printf("Enqueued: %d\n", value);
            else
                printf("Queue is full!\n");
            break;

        case 2:
            if (rq_dequeue(&queue, &value) == 0)
                printf("Dequeued: %d\n", value);
            else
                printf("Queue is empty!\n");
            break;

        case 3:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}

