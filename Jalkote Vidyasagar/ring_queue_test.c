#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_LEN 5  // Small number for easy testing

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int head;
    int tail;
    int size;
} rq_t;

// Function to initialize the queue
int rq_init(rq_t *q) {
    if (!q) return -1;
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return 0;
}

// Function to add a value to the queue
int rq_enqueue(rq_t *q, int value) {
    if (!q || q->size == MAX_QUEUE_LEN) return -1;
    q->value[q->tail] = value;
    q->tail = (q->tail + 1) % MAX_QUEUE_LEN;
    q->size++;
    return 0;
}

// Function to remove a value from the queue
int rq_dequeue(rq_t *q, int *value) {
    if (!q || q->size == 0 || !value) return -1;
    *value = q->value[q->head];
    q->head = (q->head + 1) % MAX_QUEUE_LEN;
    q->size--;
    return 0;
}

// Function to display the queue
void rq_display(rq_t *q) {
    if (q->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    int count = q->size;
    int i = q->head;
    while (count--) {
        printf("%d ", q->value[i]);
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

// Menu-driven main function
int main() {
    rq_t queue;
    int choice, value;

    rq_init(&queue);

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (rq_enqueue(&queue, value) == 0)
                    printf("Enqueued %d successfully.\n", value);
                else
                    printf("Queue is full. Cannot enqueue.\n");
                break;

            case 2:
                if (rq_dequeue(&queue, &value) == 0)
                    printf("Dequeued value: %d\n", value);
                else
                    printf("Queue is empty. Cannot dequeue.\n");
                break;

            case 3:
                rq_display(&queue);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
