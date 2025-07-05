//
// Created by Anish Sapre on 04/07/25.
//
#define MAX_QUEUE_LEN 64
#include <stdio.h>
typedef struct ring_queue{
    int front;
    int rear;
    int size;
    int value[MAX_QUEUE_LEN];
} rq_t;


int rq_init(rq_t *q) {
    if(q == NULL){
        return -1;
    }
    (*q).front = 0;
    (*q).rear = 0;
    (*q).size = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int value) {
    if ((*q).size >= MAX_QUEUE_LEN) {
        printf("ERROR\n");
        return -1;
    }
    (*q).value[(*q).rear] = value;
    (*q).rear = ((*q).rear + 1) % MAX_QUEUE_LEN;
    (*q).size++;
    printf("ENQUEUED: %d\n",value);
    return 0;
}

int rq_dequeue(rq_t *q){ //since it is a queue do I have to pass the value to be removed? It is already known isn't it?
    if ((*q).size == 0 || q == NULL) {
        printf("ERROR\n");
        return -1;
    }
    printf("DEQUEUED: %d\n", (*q).value[(*q).front]);
    (*q).front = ((*q).front + 1) % MAX_QUEUE_LEN;
    (*q).size--;
    return 0;
}

void print_queue(rq_t *q) { //i added this for debugging
    if (q == NULL || (*q).size == 0) {
        printf("ERROR\n");
        return;
    }
    printf("TOTAL ELEMENTS: %d \n", (*q).size);

    int current_element = (*q).front;
    for (int i = 0; i < (*q).size; i++) {
        printf(" %d ", (*q).value[current_element]);
        current_element = (current_element + 1) % MAX_QUEUE_LEN;  // Move circularly
    }
    printf("\nMEMBERS OF STRUCT: front=%d, rear=%d, size=%d\n", (*q).front, (*q).rear, (*q).size);
}

int main() {
    rq_t q;
    rq_init(&q);
    rq_enqueue(&q, 1);
    print_queue(&q);
    rq_enqueue(&q, 2);
    print_queue(&q);
    rq_enqueue(&q, 3);
    print_queue(&q);
    rq_dequeue(&q);
    print_queue(&q);
    rq_dequeue(&q);
    print_queue(&q);
    rq_dequeue(&q);
    print_queue(&q); //prints error but added as a check to check for an empty queue


    return 0;
}