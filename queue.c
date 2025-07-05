#include <stdio.h>
#define MAX 64

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int enqueue(Queue *q, int num) {
    int next = (q->rear + 1) % MAX;
    if (next == q->front) {
        printf("Queue Full! Can't add %d\n", num);
        return -1;
    }
    q->arr[q->rear] = num;
    q->rear = next;
    return 0;
}

int dequeue(Queue *q, int *num) {
    if (q->front == q->rear) {
        printf("Queue Empty!\n");
        return -1;
    }
    *num = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    return 0;
}

void display(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue Elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q);
    int ch, num;

    while (1) {
        printf("\n----- Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &num);
                enqueue(&q, num);
                break;
            case 2:
                if (dequeue(&q, &num) == 0)
                    printf("Removed: %d\n", num);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting\n");
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
}
