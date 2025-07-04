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

int main() {
    rq_t q;
    rq_init(&q);
    int n, val;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (rq_enqueue(&q, val) == -1) {
            printf("Queue full, can't add more.\n");
            break;
        }
    }

    printf("Dequeued elements:\n");
    while (rq_dequeue(&q, &val) == 0) {
        printf("%d\n", val);
    }

    return 0;
}
