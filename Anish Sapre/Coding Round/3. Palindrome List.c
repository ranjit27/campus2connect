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
    do  {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

void printListReverseUtil(struct node* current, struct node* head) {
    if (current->next != head)
        printListReverseUtil(current->next, head);
    printf("%d ", current->data);
}

void printListReverse(struct node* head) {
    if (head == NULL) return;
    printListReverseUtil(head, head);
}

struct node* init_list() {
    struct node* head = NULL;
    struct node* curr = NULL;
    struct node* temp = NULL;
    int arr[10] = {1,2,3,4,5,4,3,2,1};
    for (int i = 0; i < 9; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = head;

        if (head == NULL) {
            head = temp;
            curr = head;
        } else {
            curr->next = temp;
            curr = curr->next;
        }
    }
    printf("\n");
    return head;
}

void half_list(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;
    struct node* temp = head;
    do {
        slow = slow->next;
        fast = fast->next->next;
        if (fast->next == head) {
            fast->next = slow->next;
            temp->next = head;
            temp = temp->next;
            fast = fast->next;
            printListReverse(fast);
            printf("\n");
            printList(temp);
            break;
        }
        if (fast->next->next == head) {
            fast->next->next = slow->next;
            slow->next = head;
            slow = slow->next;
            fast = fast->next->next;
            printListReverse(fast);
            printf("\n");
            printList(slow);
            break;
        }
        temp = temp->next;
    }while (fast->next != head || fast->next->next != head);
}

int main() {
    struct node* list_head = init_list();
    half_list(list_head);
    return 0;
}