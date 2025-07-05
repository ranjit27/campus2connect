#include <stdio.h>
#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
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


int rq_enqueue(rq_t *q, int val) {
    if (!q || q->size == MAX_QUEUE_LEN) return -1; // Queue full
    q->value[q->rear] = val;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->size++;
    return 0;
}

int rq_dequeue(rq_t *q, int *val) {
    if (!q || q->size == 0) return -1; // Queue empty
    *val = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->size--;
    return 0;
}


int main() {
    rq_t q;
    rq_init(&q);

    rq_enqueue(&q, 10);
    rq_enqueue(&q, 20);
    rq_enqueue(&q, 30);

    int val;
    rq_dequeue(&q, &val);
    printf("Dequeued: %d\n", val);
    rq_dequeue(&q, &val);
    printf("Dequeued: %d\n", val);

    return 0;
}
