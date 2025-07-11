#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue
{
    int value[MAX_QUEUE_LEN];
    int start;
    int end;
    int size;
} rq_t;

int rq_init(rq_t *q)
{
    q->start = 0;
    q->end = 0;
    q->size = 0;

    return 0;
}

int rq_enqueue(rq_t *q, int value)
{
    if (q->size == MAX_QUEUE_LEN)
    {
        return -1;
    }

    else
    {
        q->value[q->end] = value;
        q->end = (q->end + 1) % MAX_QUEUE_LEN;
        q->size++;

        return 0;
    }
}

int rq_dequeue(rq_t *q, int *value)
{
    if (q->size == 0)
    {
        return -1;
    }

    else
    {
        *value = q->value[q->start];
        q->start = (q->start + 1) % MAX_QUEUE_LEN;
        q->size--;

        return 0;
    }
}

void main()
{
    rq_t q;
    int value;
    int op;

    rq_init(&q);

    while (1)
    {
        printf("Select operation:\n 1. Initialize new Queue\n 2. Enqueue\n 3. Dequeue\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Initializing new queue\n");
            rq_init(&q);
            break;

        case 2:
            printf("Enqueue value: ");
            scanf("%d", &value);
            if (rq_enqueue(&q, value) == 0)
                printf("Enqueued: %d\n", value);
            else
                printf("Queue Full.\n");
            break;

        case 3:
            if (rq_dequeue(&q, &value) == 0)
                printf("Dequeued: %d\n", value);
            else
                printf("Queue Empty.\n");
            break;

        default:
            return;
        }
    }
}