#include <stdio.h>
#define MAX 100

typedef struct {
    int length;
    int front;
    int rear;
    int queue[MAX];
} Queue;

int rq_isFull(Queue *q) {
    return ((q->rear + 1) % q->length == q->front);
}

int rq_isEmpty(Queue *q) {
    return (q->front == -1);
}

int rq_enqueue(Queue *q, int data) {
    if (rq_isFull(q)) {
        printf("Queue is already full\n");
        return -1;
    }

    if (rq_isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->length;
    }

    q->queue[q->rear] = data;
    return 0;
}

int deQueue(Queue *q) {
    if (rq_isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }

    int data = q->queue[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->length;
    }

    printf("Dequeue: %d\n", data);
    return 0;
}

void print_rq(Queue q) {
    if (rq_isEmpty(&q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q.front;
    printf("Queue: ");
    while (1) {
        printf("%d -> ", q.queue[i]);
        if (i == q.rear) break;
        i = (i + 1) % q.length;
    }

}

int main() {
    int l, choice, num;
      printf("Enter length of queue (MAX : 100): ");
    scanf("%d", &l);

    Queue q;
    q.length = l;
    q.front = -1;
    q.rear = -1;

    while (1) {
        printf("\nSelect your operation:\n 1. Enqueue\n 2. Dequeue\n 3. Print Queue\n 4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &num);
                rq_enqueue(&q, num);
                break;
            case 2:
                deQueue(&q);
                break;
            case 3:
                print_rq(q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
