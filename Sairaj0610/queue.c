#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN]; 
    int front;                
    int rear;                 
    int count;                // number of elements in queue
} rq_t;


int rq_init(rq_t *q) {
    if (!q) return -1;
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    return 0;
}


int rq_enqueue(rq_t *q, int val) {
    if (!q || q->count == MAX_QUEUE_LEN)
     return -1; 

    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->value[q->rear] = val;
    q->count++;
    return 0;
}


int rq_dequeue(rq_t *q, int *val) {
    if (!q || q->count == 0)
     return -1; // queue empty

    *val = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->count--;
    return 0;
}


void rq_display(rq_t *q) {
    if (q->count == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i < q->count; i++) {
        int idx = (q->front + i) % MAX_QUEUE_LEN;
        printf("%d ", q->value[idx]);
    }
    printf("\n");
}


int main() {
    rq_t q;
    rq_init(&q);

    rq_enqueue(&q, 10);
    rq_enqueue(&q, 20);
    rq_enqueue(&q, 30);

    rq_display(&q);

    int val;
    if (rq_dequeue(&q, &val) == 0)
        printf("Dequeued: %d\n", val);

    rq_display(&q);

    return 0;
}
