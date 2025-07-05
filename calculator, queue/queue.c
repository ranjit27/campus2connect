#include <stdio.h>

#define MAX_QUEUE_LEN 5

typedef struct ring_queue
{
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;  
    int count; 
} rq_t;


int rq_init(rq_t *q)
{
    if (q == NULL)
        return -1;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return 0;
}


int rq_enqueue(rq_t *q, int val)
{
    if (q == NULL)
        return -1;
    if (q->count == MAX_QUEUE_LEN)
    {
        return -1; 
    }
    q->value[q->rear] = val;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->count++;
    return 0;
}


int rq_dequeue(rq_t *q, int *val)
{
    if (q == NULL || val == NULL)
        return -1;
    if (q->count == 0)
    {
        return -1;
    }
    *val = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    q->count--;
    return 0;
}


void print_queue(rq_t *q)
{
    if (q->count == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    for (int c = 0; c < q->count; c++)
    {
        printf("%d ", q->value[i]);
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\nFront at: %d, Rear at: %d\n", q->front, q->rear);
}


int main()
{
    rq_t q;
    rq_init(&q);
    int choice, val;

    do
    {
        printf("\n--- Ring Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of values to enqueue: ");
            int n;
            scanf("%d", &n);

            for (int i = 0; i < n; i++)
            {
                if (q.count == MAX_QUEUE_LEN)
                {
                    printf("Queue is full! Cannot enqueue more values.\n");
                    break;
                }
                printf("Enter value %d: ", i + 1);
                scanf("%d", &val);
                if (rq_enqueue(&q, val) == 0)
                    printf("Enqueued %d successfully.\n", val);
                else
                    printf("Error enqueuing %d.\n", val);
            }

            print_queue(&q);
            break;

        case 2:
            if (rq_dequeue(&q, &val) == 0)
                printf("Dequeued: %d\n", val);
            else
                printf("Queue is empty! Cannot dequeue.\n");
            print_queue(&q);
            break;

        case 3:
            print_queue(&q);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
            print_queue(&q);
        }

    } while (choice != 4);

    return 0;
}
