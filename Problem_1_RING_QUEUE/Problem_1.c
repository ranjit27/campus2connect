#include <stdio.h>

#define MAX_QUEUE_LEN 64
struct ring_queue
{
    int rear, front;
    int value[MAX_QUEUE_LEN];
};
typedef struct ring_queue rq_t;

int rq_init(rq_t *q)
{
    if(q == NULL) return -1;
    q->front = 0;
    q->rear = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int value)
{
    if(q == NULL || ((q->rear + 1) % MAX_QUEUE_LEN) == q->front)
    {
        printf("Queue is Full\n");
        return -1;
    }

    q->value[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    printf("%d is enqueued\n", value);
    return 0;
}

int rq_dequeue(rq_t *q, int *value)
{
    if(q == NULL || q->front == q->rear)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    *value = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    printf("%d is dequeued\n", *value);
    return 0;
}

int rq_display(rq_t *q)
{
    if(q == NULL || q->front == q->rear)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    printf("\nQueue is: ");
    int i = q->front;
    while (i != q->rear)
    {
        printf("%d ", q->value[i]);
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
    return 0;
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int choice;
    rq_t queue;
    rq_init(&queue);

    while (1)
    {
        printf("\n1: ENQUEUE\n2: DEQUEUE\n3: DISPLAY\n4: EXIT\n");
        printf("Enter your choice (1 - 4): ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Enter your choice (1 - 4)\n");
            clear_input_buffer();
            continue;
        }

        switch(choice)
        {
            case 1: 
                int value;
                printf("Enter value to enqueue: ");
                if (scanf("%d", &value) != 1) 
                {
                    printf("Please enter a number only.\n");
                    clear_input_buffer();
                    continue;
                }
                rq_enqueue(&queue, value);
                break;
        

            case 2: 
                int value;
                rq_dequeue(&queue, &value);
                break;
            

            case 3:
                rq_display(&queue);
                break;

            case 4:
                break;

            default:
                printf("Invalid choice. Enter your choice (1 - 4).\n");
                break;
        }
    }

    return 0;
}
