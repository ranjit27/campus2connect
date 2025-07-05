#include <stdio.h>
#define MAX_QUEUE_LEN 65

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
    int count;
} rq_t;

// Initialize the queue
int rq_init(rq_t *q) {
    if (!q) return -1;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return 0;
}

// Enqueue operation
int rq_enqueue(rq_t *q, int val) {
    if (!q) return -1;
    if (q->count == MAX_QUEUE_LEN) return -1; // Queue is full

    q->value[q->rear] = val;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->count++;
    return 0;
}

// Dequeue operation
int rq_dequeue(rq_t *q, int *val) {
    if (!q || !val) return -1;
    if (q->count == 0) return -1; // Queue is empty

    *val = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->count--;
    return 0;
}

// Print queue state
void print_queue(rq_t *q) {
    if (q->count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;
    for (int c = 0; c < q->count; c++) {
        printf("%d ", q->value[i]);
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\nFront at: %d, Rear at: %d\n", q->front, q->rear);
}

int main() {
    rq_t q;
    rq_init(&q);

    int choice, val;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
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
            if (rq_enqueue(&q, val) == -1)
                printf("Queue is Full!\n");
            else
                printf("%d enqueued successfully.\n", val);
            break;

        case 2:
            if (rq_dequeue(&q, &val) == -1)
                printf("Queue is Empty!\n");
            else
                printf("Dequeued: %d\n", val);
            break;

        case 3:
            print_queue(&q);
            break;

        case 4:
            printf("Exit.\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}



/*
----------------------IMP Points Or Notes----------------------

-> there are 3 main conditions we have to check in case of ring queue:
  1. Queue is Empty
    ---------if (count == 0)------------
    This means there is nothing in the queue.
    No elements are added yet, or all elements were removed.

  2. Queue is Full
     ----------if (count == MAX_QUEUE_LEN)----------
      add (enqueue) more elements without checking, it will overwrite data or go out of bounds

  3. Queue is not full and not empty
     ---------rear = (rear + 1) % MAX_QUEUE_LEN;--------
     ---------front = (front + 1) % MAX_QUEUE_LEN;---------

     queue is a circle, not a straight line.
     So if we reach the end (say, index 4 in an array of size 5), you come back to the beginning (index 0).
     This % (modulo) operator helps us do that.
     If rear is at index 4, (4 + 1) % 5 = 0, so next insert will happen at index 0.

*/
