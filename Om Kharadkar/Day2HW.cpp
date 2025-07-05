#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_LEN 10

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
} rq_t;


int rq_init(rq_t *q) {
    if (!q) return -1;
    q->front = 0;
    q->rear = -1;
    return 0;
}


int rq_enqueue(rq_t *q, int ele) {
    if (!q) return -1;

    if ((q->front == 0 && q->rear == MAX_QUEUE_LEN - 1) || 
        (q->front == (q->rear + 1) % MAX_QUEUE_LEN && q->front != 0)) {
        
        return -1;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->value[q->rear] = ele;
    return 0;
}


int rq_dequeue(rq_t *q, int *ele) {
    if (!q || !ele) return -1;

    if (q->front == 0 && q->rear == -1) {
        
        return -1;
    }

    *ele = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;

    if (q->front == (q->rear + 1) % MAX_QUEUE_LEN) {
        q->front = 0;
        q->rear = -1;
    }

    return 0;
}


void rq_display(rq_t *q) {
    if (q->front == 0 && q->rear == -1) {
        printf("Nothing to display..!\n");
    } else {
        printf("Queue contains....!\n");
        int i = q->front;
        do {
            printf("%d(%d)\t", q->value[i], i);
            i = (i + 1) % MAX_QUEUE_LEN;
        } while (i != (q->rear + 1) % MAX_QUEUE_LEN);
        printf("\n");
    }
}

int main() {
    rq_t q;
    rq_init(&q);

    int ch, ele, result;
    do {
        printf("\nSelect your choice:\n");
        printf("1 - Insert\n");
        printf("2 - Remove\n");
        printf("3 - Display\n");
        printf("4 - Exit\n");
        printf("Provide your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to insert into circular Queue: ");
                scanf("%d", &ele);
                result = rq_enqueue(&q, ele);
                if (result == -1)
                    printf("Queue overflow...!\n");
                else
                    printf("Element %d is inserted into circular queue...!\n", ele);
                break;
            case 2:
                result = rq_dequeue(&q, &ele);
                if (result == -1)
                    printf("Queue Underflow...!\n");
                else
                    printf("%d element is removed from Circular Queue....!\n", ele);
                break;
            case 3:
                rq_display(&q);
                break;
            case 4:
                exit(0);
        }
    } while (1);

    return 0;
}

