#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
} rq_t;

int rq_init(rq_t *q) {
    if (q == NULL) {
        return -1;
    }
    
    q->front = 0;
    q->rear = -1;
    return 0;
}

int rq_enqueue(rq_t *q, int value) {
    if (q == NULL) {
        return -1;
    }
    
    if (q->rear == MAX_QUEUE_LEN - 1 && q->front == 0) {
        printf("Ring queue overflow\n");
        return -1;
    }
    else if (q->front == (q->rear + 1) % MAX_QUEUE_LEN && q->front != 0) {
        printf("Ring queue overflow\n");
        return -1;
    }
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
        q->value[q->rear] = value;
        printf("Element %d inserted in ring queue\n", value);
        return 0;
    }
}

int rq_dequeue(rq_t *q, int value) {
    if (q == NULL) {
        return -1;
    }
    
    if (q->front == 0 && q->rear == -1) {
        printf("Queue underflow\n");
        return -1;
    }
    else {
        value = q->value[q->front];
        printf("Element %d is removed from queue\n", value);
        q->front = (q->front + 1) % MAX_QUEUE_LEN;
        
        if (q->front == (q->rear + 1) % MAX_QUEUE_LEN) {
            q->front = 0;
            q->rear = -1;
        }
        return 0;
    }
}

void display_queue(rq_t *q) {
    if (q == NULL) {
        printf("Invalid queue\n");
        return;
    }
    
    if (q->front == 0 && q->rear == -1) {
        printf("Queue is empty, nothing to display\n");
    }
    else {
        printf("Ring queue contains: ");
        int i = q->front;
        do {
            printf("%d\t", q->value[i]);
            i = (i + 1) % MAX_QUEUE_LEN;
        } while (i != (q->rear + 1) % MAX_QUEUE_LEN);
        printf("\n");
    }
}

int main() {
    rq_t queue;
    int ch, val, dq_val;
    
    if (rq_init(&queue) != 0) {
        printf("Failed to initialize queue\n");
        return -1;
    }
    
    do {
        printf("\n\nChoices\n");
        printf("1- Insert (Enqueue)\n");
        printf("2- Remove (Dequeue)\n");
        printf("3- Display\n");
        printf("4- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                if (rq_enqueue(&queue, val) != 0) {
                    printf("Failed to enqueue element\n");
                }
                break;
                
            case 2:
                if (rq_dequeue(&queue, dq_val) == 0) {
                } else {
                    printf("Failed to dequeue element\n");
                }
                break;
                
            case 3:
                display_queue(&queue);
                break;
                
            case 4:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (1);
    
    return 0;
}