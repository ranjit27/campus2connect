#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_LEN 100

typedef struct Queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
} rq_t;

void init_queue(rq_t *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(rq_t *q) {
    return q->front > q->rear;
}

void enqueue(rq_t *q, int val) {
    if (q->rear == MAX_QUEUE_LEN - 1) {
        printf("Queue is full\n");
        return;
    }
    q->value[++(q->rear)] = val;
}

int dequeue(rq_t *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->value[(q->front)++];
}

void display(rq_t *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->value[i]);
    }
    printf("\n");
}

void reverseFirstK(rq_t *q, int k) {
    if (k <= 0 || k > q->rear - q->front + 1) {
        printf("Invalid value of k\n");
        return;
    }
    int arr[MAX_QUEUE_LEN];
    int count = -1;

    for (int i = 0; i < k; i++) {
        arr[++count] = dequeue(q);
    }

    int temp[MAX_QUEUE_LEN]; 
    int idx = 0;

    while (count != -1) {
        temp[idx++] = arr[count--];
    }

    while (!isEmpty(q)) {
        temp[idx++] = dequeue(q);
    }

    init_queue(q);
    for (int i = 0; i < idx; i++) {
        enqueue(q, temp[i]);
    }
}

int main() {
    rq_t q;
    int n, k, val;

    init_queue(&q);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    printf("Enter k (number of elements to reverse): ");
    scanf("%d", &k);

    printf("Original Queue:\n");
    display(&q);

    reverseFirstK(&q, k);

    printf("Queue after reversing first %d elements:\n", k);
    display(&q);

    return 0;
}
