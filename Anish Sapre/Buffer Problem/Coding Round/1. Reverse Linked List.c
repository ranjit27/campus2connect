//
// Created by Anish Sapre on 10/07/25.
//
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
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverse_print(struct node* head) {
    if (head == NULL) return;
    reverse_print(head->next);
    printf("%d ", head->data);
}


struct node* init_list() {
    struct node* head = NULL;
    struct node* curr = NULL;
    struct node* temp = NULL;

    for (int i = 1; i <= 5; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = i;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            curr = head;
        } else {
            curr->next = temp;
            curr = curr->next;
        }
    }
    return head;
}

int main() {

    struct node* head = init_list();
    reverse_print(head);
    printf("\n");
    printList(head);
    return 0;
}