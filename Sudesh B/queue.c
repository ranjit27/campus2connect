#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
} rq_t;


int rq_init(rq_t *q) {
    if (!q) return -1; 
    q->front = 0;
    q->rear = 0;
    return 0; 
}


int rq_enqueue(rq_t *q, int value) {
    if (!q) return -1; 
    int next_rear = (q->rear + 1) % MAX_QUEUE_LEN;

    
    if (next_rear == q->front) {
        return -1; 
    }

    q->value[q->rear] = value;
    q->rear = next_rear;
    return 0; 
}

int rq_dequeue(rq_t *q, int *value) {
    if (!q || !value) return -1; 
    if (q->front == q->rear) {
        return -1; 
    }

    *value = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    return 0; 
}


int main() {
    rq_t queue;
    int result;

    
    result = rq_init(&queue);
    if (result == -1) {
        printf("Failed to initialize the queue.\n");
        return EXIT_FAILURE;
    }

    // Enqueue elements
    for (int i = 0; i < 10; i++) {
        if (rq_enqueue(&queue, i) == -1) {
            printf("Failed to enqueue %d. Queue might be full.\n", i);
        }else{
            printf("Enqueued: %d\n", i);
        }
    }

    // Dequeue elements
    printf("\n");
    int value;
    for (int i = 0; i < 10; i++) {
        if (rq_dequeue(&queue, &value) == -1) {
            printf("Failed to dequeue. Queue might be empty.\n");
        } else {
            printf("Dequeued: %d\n", value);
        }
    }

    return EXIT_SUCCESS;
}
