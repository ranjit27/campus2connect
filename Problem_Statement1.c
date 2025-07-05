#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
    int count;
} rq_t;

int rq_init(rq_t *q) {
    if (!q) return -1;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int value) {
    if (!q || q->count == MAX_QUEUE_LEN) return -1;
    q->value[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->count++;
    return 0;
}

int rq_dequeue(rq_t *q, int *value) {
    if (!q || q->count == 0) return -1;
    *value = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->count--;
    return 0;
}

void rq_display(rq_t *q) {
    if (!q || q->count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    int i, index;
    printf("Queue: ");
    for (i = 0, index = q->front; i < q->count; i++) {
        printf("%d ", q->value[index]);
        index = (index + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

int main() {
    rq_t queue;
    int choice, val, ret;

    rq_init(&queue);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. View Queue\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            ret = rq_enqueue(&queue, val);
            if (ret == -1)
                printf("Queue is full.\n");
            else
                printf("Enqueued %d\n", val);
        } else if (choice == 2) {
            ret = rq_dequeue(&queue, &val);
            if (ret == -1)
                printf("Queue is empty.\n");
            else
                printf("Dequeued %d\n", val);
        } else if (choice == 3) {
            rq_display(&queue);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

