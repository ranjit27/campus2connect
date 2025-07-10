#include <stdio.h>
#include <stdlib.h>

/*
Problem Statement

Implement a FIFO ring queue of integers using an array
Add code for rq_init,rq_enqueue and rq_dequeue
All functions should return -1 if error occurs otherwise 0 if successful

you will need to add the members to below structure

*/

#define MAX_QUEUE_LEN 64

typedef struct ring_queue
{

    int value[MAX_QUEUE_LEN];
    int rear;
    int front;

} rq_t;

// init ring queue
int rq_init(rq_t *q)
{

    q->front = -1;
    q->rear = -1;
    return 0;
}

// add value at end of ring queue
int rq_enqueue(rq_t *q, int value)
{
    if ((q->rear + 1) % MAX_QUEUE_LEN == q->front)
    {
        printf("queue is full\n");
        return -1;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }
    printf("rear is at:%d\n", q->rear);

    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->value[q->rear] = value;

    printf("value enqueued:%d\n", q->value[q->rear]);
    printf("rear is at:%d\n", q->rear);
    printf("--------------------------\n");
    return 1;
}

// remove value
int rq_dequeue(rq_t *q)
{
    if (q->front == -1)
    {
        printf("queue is empty\n");
        return -1;
    }
    printf("front is at:%d\n", q->front);

    int val = q->value[q->front];
    printf("dequed value:%d\n", val);

    // single element dequeued
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_QUEUE_LEN;
        printf("front is at:%d\n", q->front);
        printf("----------------------------------\n");
    }

    return 0;
}

int main()
{

    rq_t q;
    rq_init(&q);

    int choice;
    int value;

    do
    {
        printf("1.Enqueue\n2.Dequeue\n0.Exit\n");
        printf("enter the choice:\n");
        scanf("%d/n ", &choice);

        switch (choice)
        {
        case 1:
            printf("enter value to enqueue:\n");
            scanf("%d", &value);
            rq_enqueue(&q, value);
            break;

        case 2:
            printf("-----Dequeue------\n");
            rq_dequeue(&q); // it will remove the first in value
            break;
        case 0:
            printf("exiting......\n");
            exit(0);
            break;
        }

    } while (choice != 0);
}