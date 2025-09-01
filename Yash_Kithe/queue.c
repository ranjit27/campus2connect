#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue
{
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
    int count;
} rq_t;

int rq_init(rq_t *q)
{
    if (!q) return -1;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int value)
{
    if (!q) return -1;
    if (q->count == MAX_QUEUE_LEN) return -1; 
     q->value[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->count++;
    return 0;
}

int rq_dequeue(rq_t *q, int *value)
{
    if (!q || !value) return -1;
    if (q->count == 0) return -1; 
    *value = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->count--;
return 0;
}

void rq_print(const rq_t *q) {
    if (!q || q->count == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    int idx = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->value[idx]);
        idx = (idx + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

int main() {
    rq_t queue;
    rq_init(&queue);
  for (int i = 1; i <= 5; i++) {
        rq_enqueue(&queue, i * 10);
    }
    rq_print(&queue);
    int val;
    rq_dequeue(&queue, &val);
    printf("Dequeued: %d\n", val);
    rq_dequeue(&queue, &val);
    printf("Dequeued: %d\n", val);  
    rq_print(&queue);

    return 0;
}