#include <stdio.h>
#define MAX_QUEUE_LEN 64

typedef struct {
    int value[MAX_QUEUE_LEN];
    int head;
    int tail;
} rq_t;

int rq_init(rq_t *q) {
    q->head = 0;
    q->tail = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int value) {
    int next_tail = (q->tail + 1) % MAX_QUEUE_LEN;
    if (next_tail == q->head) {
        return -1; 
    }
    q->value[q->tail] = value;
    q->tail = next_tail;
    return 0;
}

int rq_dequeue(rq_t *q, int *value) {
    if (q->head == q->tail) {
        return -1; 
    }
    *value = q->value[q->head];
    q->head = (q->head + 1) % MAX_QUEUE_LEN;
    return 0;
}

// Display queue elements
void rq_display(rq_t *q) {
    if (q->head == q->tail) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    int i = q->head;
    while (i != q->tail) {
        printf("%d ", q->value[i]);
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

int main() {
    rq_t q;
    rq_init(&q);
    int choice, val;

    while (1) {
        printf("\n---- Queue Menu ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                if (rq_enqueue(&q, val) == -1) {
                    printf("Queue is full, Cannot enqueue.\n");
                } else {
                    printf("Enqueued %d successfully.\n", val);
                }
                break;

            case 2:
                if (rq_dequeue(&q, &val) == -1) {
                    printf("Queue is empty, Cannot dequeue.\n");
                } else {
                    printf("Dequeued value: %d\n", val);
                }
                break;

            case 3:
                rq_display(&q);
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice...\n");
        }
    }
}
