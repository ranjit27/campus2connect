//
// Created by Anish Sapre on 05/07/25.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) { //goes into infinite loop when run because it is circular, just a test for the buffer implementation
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node* head = NULL;
    struct node* curr = NULL;
    struct node* temp = NULL;

    for (int i = 1; i <= 5; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = i;
        temp->next = head;

        if (head == NULL) {
            head = temp;
            curr = head;
        } else {
            curr->next = temp;
            curr = curr->next;
        }
    }
    printList(head);
    return 0;
}