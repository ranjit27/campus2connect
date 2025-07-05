#include <stdio.h>
#include <stdlib.h>
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
    if (value)
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

    printf("Queue contents: ");
    int i, index;
    for (i = 0, index = q->front; i < q->count; i++) {
        printf("%d ", q->value[index]);
        index = (index + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

int main() {
    rq_t q;
    int choice, value;
    rq_init(&q);
    while (1) {
        printf("\nCircular Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (rq_enqueue(&q, value) == 0)
                    printf("Enqueued %d successfully\n", value);
                else
                    printf("Queue is full! Cannot enqueue\n");
                break;

            case 2:
                if (rq_dequeue(&q, &value) == 0)
                    printf("Dequeued value: %d\n", value);
                else
                    printf("Queue is empty! Cannot dequeue\n");
                break;

            case 3:
                rq_display(&q);
                break;

            case 4:
                printf("Exiting program\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter 1-4\n");
        }
    }
return 0;
}