#include <stdio.h>
#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int head;
    int tail;
    int size;
} rq_t;

// Initialize the ring queue
int rq_init(rq_t *q) {
    if (!q) return -1;
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return 0;
}

// Add value to the end of ring queue
int rq_enqueue(rq_t *q, int value) {
    if (!q || q->size == MAX_QUEUE_LEN) return -1; // queue full

    q->value[q->tail] = value;
    q->tail = (q->tail + 1) % MAX_QUEUE_LEN;
    q->size++;
    return 0;
}

// Remove value from front of queue and store it in *value
int rq_dequeue(rq_t *q, int *value) {
    if (!q || q->size == 0 || !value) return -1; // queue empty or invalid

    *value = q->value[q->head];
    q->head = (q->head + 1) % MAX_QUEUE_LEN;
    q->size--;
    return 0;
}
