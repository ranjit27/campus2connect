#include <stdio.h>
#define SIZE 65

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
    int count;
} Q;

int init(Q *Q) {
    if (!Q) return -1;
    Q->front = 0;
    Q->rear = 0;
    Q->count = 0;
    return 0;
}

int enQ(Q *Q, int data) {
    if (!Q) return -1;
    if (Q->count == SIZE) return -1;
    Q->arr[Q->rear] = data;
    Q->rear = (Q->rear + 1) % SIZE;
    Q->count++;
    return 0;
}

int deQ(Q *Q, int *data) {
    if (!Q || !data) return -1;
    if (Q->count == 0) return -1;
    *data = Q->arr[Q->front];
    Q->front = (Q->front + 1) % SIZE;
    Q->count--;
    return 0;
}

void display(Q *Q) {
    if (Q->count == 0) {
        printf("Q is empty.\n");
        return;
    }

    printf("Q: ");
    int idx = Q->front;
    for (int i = 0; i < Q->count; i++) {
        printf("%d ", Q->arr[idx]);
        idx = (idx + 1) % SIZE;
    }
    printf("\nFront at: %d, Rear at: %d\n", Q->front, Q->rear);
}

int main() {
    Q Q;
    init(&Q);

    int option, data;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. EnQ\n");
        printf("2. DeQ\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            if (enQ(&Q, data) == -1)
                printf("Q is full.\n");
            else
                printf("%d added.\n", data);
            break;
        case 2:
            if (deQ(&Q, &data) == -1)
                printf("Q is empty.\n");
            else
                printf("Removed: %d\n", data);
            break;
        case 3:
            display(&Q);
            break;
        case 4:
            printf("Exiting.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
