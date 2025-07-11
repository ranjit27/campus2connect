#include <stdio.h>
#define MAX_QUEUE_LEN 20

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
    int size;
} rq_t;

int rq_init(rq_t *q) {
    if (!q) {
        return -1;
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int val) {
    if (!q || q->size == MAX_QUEUE_LEN) {
        printf("Queue is full. %d\n", val);
        return -1;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->value[q->rear] = val;
    q->size++;
    return 0;
}

int rq_dequeue(rq_t *q, int *val) {
    if (!q || q->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    *val = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->size--;
    return 0;
}

void rq_print(rq_t *q) {
    if (!q || q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_QUEUE_LEN;
        printf("%d ", q->value[index]);
    }
    printf("\n");
}

int main() {
    rq_t queue;
    rq_init(&queue);
    int choice, n, val, i;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");  
        printf("4. Exit\n");         
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number of elements to enqueue: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                printf("Enter value %d: ", i + 1);
                scanf("%d", &val);
                rq_enqueue(&queue, val);
            }
        } else if (choice == 2) {
            if (rq_dequeue(&queue, &val) == 0) {
                printf("Dequeued: %d\n", val);
            }
        } else if (choice == 3) { 
            rq_print(&queue);
        } else if (choice == 4) { 
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

