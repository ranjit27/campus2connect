// Problem Statement:
// Implement a FIFO ring queue of integers using an array
// Add code for rq_init, rq_enqueue, rq_dequeue.
// All functions should return -1 if error occurs, otherwise 0 if successfull,

// You will need to add the members to the below structure

#include<stdio.h>
#define MAX_QUEUE_LEN 64

typedef struct ring_queue
{
    int value[MAX_QUEUE_LEN];
    int head;
    int tail;
} rq_t;

/* init ring queue */
int rq_init(rq_t *q)
{
    if (!q) 
    {
       return -1;
    }
    else
    {
        q->head = 0;
        q->tail = 0;
        return 0;
    }
}

/* Add value to the end of rign queue */
int rq_enqueue(rq_t *q, int value)
{
    if(!q)
    {
        return -1;
    }
    else
    {
        int next_tail = (q->tail+1) % MAX_QUEUE_LEN;
        if (next_tail != q->head)
        {
            q->value[q->tail] = value;
            q->tail = next_tail;
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

/* Remove Value */
int rq_dequeue(rq_t *q, int *value)
{
    if(!q || !value)
    {
        return -1;
    }
    else
    {
        if (q->head == q->tail)
        {
            return -1;
        }
        else
        {
            *value = q->value[q->head];
            q->head = (q->head + 1) % MAX_QUEUE_LEN;
            return 0;
        }
    }
}

void rq_print(rq_t *q) {
    if (!q) return;

    if (q->head == q->tail) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current Queue: ");
    int i = q->head;
    while (i != q->tail) {
        printf("%d -> ", q->value[i]);
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

int main()
{
    rq_t q;
    rq_init(&q);

    int choice, value;
    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            if (rq_enqueue(&q, value) == 0)   
            {
                printf("Enqueued %d successfully.\n", value);
            }
            else
            {
                printf("Queue is full.\n");
            }

            rq_print(&q);
        }
        else if (choice == 2) {
            if (rq_dequeue(&q, &value) == 0)
            {
                printf("Dequeued: %d\n", value);
            }
            else
            {
                printf("Queue is empty.\n");
            }

            rq_print(&q);
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }
}
