#include<stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue{

    int data[MAX_QUEUE_LEN];
    int front;
    int rear;
    int count;

} rq_t;

int rq_init( rq_t *q)
{
    if( !q ) return -1;
    q->front=0;
    q->rear=0;
    q->count=0;
    return 0;
}

int rq_enqueue( rq_t *q , int value)
{
    if( !q)
    {
        return -1;
    }
    if( q->count == MAX_QUEUE_LEN)
    {
        return -1;
    }

    q->data[q->rear]=value;
    q->rear=(q->rear+1) % MAX_QUEUE_LEN;
    q->count++;
    return 0; 
}

int rq_dequeue( rq_t *q , int *value )
{
    if( !q || value== NULL)
    {
        return -1;
    }
    if( q->count == 0)
    {
        return -1;
    }
    *value = q->data[q->front];
    q->front= ( q->front+1 ) % MAX_QUEUE_LEN;
    q->count--;
    return 0;
}

void rq_print(rq_t *q) {
    printf("Queue contents: ");
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->data[(q->front + i) % MAX_QUEUE_LEN]);
    }
    printf("\n");
}


int main(void)
{
    rq_t q;
    rq_init(&q);

    int choice, value;
    while (1)
    {
        printf("\n Queue Menu \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter a value to enqueue: ");
            scanf("%d", &value);
            if (rq_enqueue(&q, value) == 0)
            {
                printf("Value enqueued.\n");
            }
            else
            {
                printf("Queue is full!\n");
            }
        }
        else if (choice == 2)
        {
            if (rq_dequeue(&q, &value) == 0)
            {
                printf("Dequeued value: %d\n", value);
            }
            else
            {
                printf("Queue is empty!\n");
            }
        }
        else if (choice == 3)
        {
            printf("Exiting.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }

        printf("Queue now: ");
        rq_print(&q);
    }


}