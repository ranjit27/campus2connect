#include <stdio.h>

#define MAX_QUEUE_LEN 70

typedef struct ring_queue {
    int data[MAX_QUEUE_LEN];
    int front;
    int rear;
    int size;
} rq_t;

int rq_init(rq_t *q) {
    if (!q) return -1;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int value) {
    if (!q || q->size == MAX_QUEUE_LEN)
        return -1;

    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->size++;
    return 0;
}

int rq_dequeue(rq_t *q, int *value) {
    if (!q || q->size == 0)
        return -1;

    if (value)
        *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->size--;
    return 0;
}

void rq_display(rq_t *q) {
    if (!q || q->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i, idx;
    for (i = 0, idx = q->front; i < q->size; i++) {
        printf("%d ", q->data[idx]);
        idx = (idx + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

int main() {
    rq_t queue;
    int choice, val;

    rq_init(&queue);

    while (1) {
        printf("\nMenu:\n");
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
                if (rq_enqueue(&queue, val) == 0)
                    printf("Enqueued successfully.\n");
                else
                    printf("Queue is full.\n");
                break;

            case 2:
                if (rq_dequeue(&queue, &val) == 0)
                    printf("Dequeued: %d\n", val);
                else
                    printf("Queue is empty.\n");
                break;

            case 3:
                rq_display(&queue);
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