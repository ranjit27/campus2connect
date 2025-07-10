
#include<stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue {

    int front;
    int rear;
    int value[MAX_QUEUE_LEN];

} rq_t;

int enqueue(int data , rq_t *rq);
int dequeue(rq_t *rq , int * out_param);
void printData(rq_t *rq);
int init(rq_t *rq);

#define CHECK(ret_val, msg)              \
    do {                                 \
        if ((ret_val) == 0) {                \
            printf("Error: %s\n", msg);  \
            break;                    \
        }                                \
        else{                           \
            printf("Success\n");\
            break;\
        }\
    } while(0)

int init(rq_t *rq) {
    if(rq == NULL) {
        return 0;
    }
    rq->front = -1;
    rq->rear = -1;

    return 1;
}

int enqueue(int data , rq_t *rq) {

    if((rq->rear + 1) % MAX_QUEUE_LEN == rq->front) {
        return 0;
    }

    if(rq->front == -1 && rq->rear == -1) {
        rq->front = 0;
        rq->rear = 0;
    }
    else {
        rq->rear = (rq->rear + 1) % MAX_QUEUE_LEN;
    }

    rq->value[rq->rear] = data;

    return 1;
}

int dequeue(rq_t *rq , int * out_param) {
    if(rq->front == -1 && rq->rear == -1) {
        return 0;
    }
    else if(rq->front == rq->rear) {
        rq->front = -1;
        rq->rear = -1;
        return 0;
    }
    else {
        *out_param = rq->value[rq->front];
        rq->front = (rq->front + 1) % MAX_QUEUE_LEN;
    }

    return 1;
}

void printData(rq_t *rq) {
    if(rq->front == -1 && rq->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = rq->front;
    while (1) {
        printf("%d ", rq->value[i]);
        if (i == rq->rear) {
            break;
        }
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

int main() {
    rq_t rq;
    int choice, val, out_val;
    int initialized = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Initialize Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                init(&rq);
                initialized = 1;
                break;
            case 2:
                if (!initialized) {
                    printf("Queue not initialized\n");
                    break;
                }
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                CHECK(enqueue(val, &rq), "enqueue failed");
                break;
            case 3:
                if (!initialized) {
                    printf("Queue not initialized\n");
                    break;
                }
                if (dequeue(&rq, &out_val)) {
                    printf("Dequeued element: %d\n", out_val);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 4:
                if (!initialized) {
                    printf("Queue not initialized\n");
                    break;
                }
                printData(&rq);
                break;
            case 5:
                printf("Exiting.........\n");
                printf("Thank you for using my application\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
