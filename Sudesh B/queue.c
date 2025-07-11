#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue
{
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
} rq_t;

int rq_init(rq_t *q)
{
    if (!q)
        return -1;
    q->front = 0;
    q->rear = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int value)
{
    if (!q)
        return -1;
    int next_rear = (q->rear + 1) % MAX_QUEUE_LEN;

    if (next_rear == q->front)
    {
        return -1;
    }

    q->value[q->rear] = value;
    q->rear = next_rear;
    return 0;
}

int rq_dequeue(rq_t *q, int *value)
{
    if (!q || !value)
        return -1;
    if (q->front == q->rear)
    {
        return -1;
    }

    *value = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    return 0;
}

int main()
{
    rq_t queue;
    int result;

    result = rq_init(&queue);
    if (result == -1)
    {
        printf("Failed to initialize the queue.\n");
        return EXIT_FAILURE;
    }

    // Enqueue elements
    // for (int i = 0; i < 10; i++) {
    //     if (rq_enqueue(&queue, i) == -1) {
    //         printf("Failed to enqueue %d. Queue might be full.\n", i);
    //     }else{
    //         printf("Enqueued: %d\n", i);
    //     }
    // }

    
    // // Dequeue elements
    // printf("\n");
    // int value;
    // for (int i = 0; i < 10; i++)
    // {
    //     if (rq_dequeue(&queue, &value) == -1)
    //     {
    //         printf("Failed to dequeue. Queue might be empty.\n");
    //     }
    //     else
    //     {
    //         printf("Dequeued: %d\n", value);
    //     }
    // }



    //MENU DRIVEN ENQUEQE and DEQUEUE 
    int choice;
    int inp, n , value;

    do
    {
        printf("_______________________");
        printf("\n1.Enqueue elements \n2.Dequeue elements \n3Exit \n");
        printf("\nEnter choice : \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("\nEnter the number of elements to add in queue : \n");
            scanf("%d", &n);
            
            for (int i = 0; i < n; i++)
            {
                printf("\nEnter in Queue : \n");
                scanf("%d", &inp);

                if (rq_enqueue(&queue, inp) == -1)
                {
                    printf("Failed to enqueue %d. Queue might be full.\n", i);
                }
                else
                {
                    printf("Enqueued: %d\n", inp);
                }
            }
            break;
        }

        case 2:
        {
            printf("\n");
            while(rq_dequeue(&queue, &value) != -1){
                printf("Dequeued: %d\n", value);
            }
            printf("\n");
            break;
        }

        case 3:
            printf("\nExiting the program.....");
            break;
        }

    } while (choice == 1 || choice == 2);

    return EXIT_SUCCESS;
}
