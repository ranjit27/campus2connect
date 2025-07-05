#include <stdio.h>

#define MAX_QUEUE_LEN 64

// ring queue struct
typedef struct ring_queue {
    int front;
    int rear;
    int value[MAX_QUEUE_LEN];
} rq_t;


int rq_init(rq_t *q) {
    if (q == NULL) return -1;
    q->front = 0;
    q->rear = 0;
    return 0;
}

// check full
int is_full(rq_t *q) {
    return ((q->rear + 1) % MAX_QUEUE_LEN) == q->front;
}

// check empty
int is_empty(rq_t *q) {
    return q->front == q->rear;
}


int rq_enqueue(rq_t *q, int val) {
    if (q == NULL || is_full(q)) return -1;
    q->value[q->rear] = val;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    return 0;
}


int rq_dequeue(rq_t *q, int *val) {
    if (q == NULL || is_empty(q)) return -1;
    *val = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    return 0;
}

// print queue
void print_queue(rq_t *q) {
    if (q == NULL || is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->value[i]);
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\nFront index: %d, Rear index: %d\n", q->front, q->rear);
}


void flush_input() {
    while (getchar() != '\n');
}


int main() {
    rq_t q;
    rq_init(&q);

    int choice = 0, num, result;

    do {
        printf("\n--- FIFO Ring Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            flush_input();
            choice = 0; 
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                if (scanf("%d", &num) != 1) {
                    printf("Invalid input. Try again.\n");
                    flush_input();
                    break;
                }
                result = rq_enqueue(&q, num);
                if (result == 0)
                    printf("Enqueued %d\n", num);
                else
                    printf("Queue is full.\n");
                break;

            case 2:
                result = rq_dequeue(&q, &num);
                if (result == 0)
                    printf("Dequeued %d\n", num);
                else
                    printf("Queue is empty.\n");
                break;

            case 3:
                print_queue(&q);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
