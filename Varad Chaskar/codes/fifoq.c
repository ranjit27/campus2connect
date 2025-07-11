#include <stdlib.h>
#include <stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue
{
    int front;
    int rear;
    int value[MAX_QUEUE_LEN];   
} rq_t;

int rq_init(rq_t *q)
{
    if (q == NULL) return -1;
    q->front=0;
    q->rear=0;
    return 0;       
}

int isFull(rq_t *q)
{
    return ((q->rear + 1)% MAX_QUEUE_LEN)== q->front;
}

int isEmpty(rq_t *q)
{
    return q->front ==q->rear;
}

int rq_enqueue(rq_t *q, int value)
{
    if(isFull(q))
    {
        printf("Queue Full\n");
        return -1;
    }       
    q->value[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    return 0;       
}

int rq_dequeue(rq_t *q, int *value)
{
    if(isEmpty(q))
    {
        printf("Queue Empty\n");
        return -1;
    }
    *value = q->value[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    return 0;
}   

int top(rq_t *q)
{
    if(isEmpty(q))
    {
        printf("Empty Queue");
        return -1;
    }
    return q->value[q->front];
}
int main() 
{
    rq_t q;
    rq_init(&q);
    int ch = 0,num,res;
    
    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Top\n4. Display whole Queue\n5. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value to enqueue\n");
            scanf("%d",&num);
            rq_enqueue(&q,num);
            break;

            case 2:
            rq_dequeue(&q,&num);
            break;

            case 3:
            printf("Top: %d\n",top(&q));
            break;

            case 4:
            if (isEmpty(&q)) 
            {
                printf("Queue is empty.\n");
            } 
            else 
            {
                printf("Queue contents: ");
                int i = q.front;
                while (i != q.rear) {
                    printf("%d ", q.value[i]);
                    i = (i + 1) % MAX_QUEUE_LEN;
                }
                printf("\n");
            }
            break;

            case 5: 
            exit(0);
            break;

            default:
            printf("Invalid Choice");
            break;
        }

    }
}
