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


struct node* init_list() {
    struct node* head = NULL;
    struct node* curr = NULL;
    struct node* temp = NULL;
    int arr[10] = {1,2,3,4,5,5,4,3,2,1};
    for (int i = 0; i < 10; i++) {
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
    printList(head);
    printf("\n");
    return head;
}

void half_list(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;
    do {
        slow = slow->next;
        fast = fast->next->next;
        if (fast->next == head) {
            fast->next = slow->next;
            slow->next = head;
            slow = slow->next;
            fast = fast->next;
            break;
        }
        if (fast->next->next == head) {
            fast->next->next = slow->next;
            slow->next = head;
            slow = slow->next;
            fast = fast->next->next;
            break;
        }
    }while (fast->next != head || fast->next->next != head);
    printList(fast);
    printf("\n");
    printList(slow);
}

int main() {
    struct node* list_head = init_list();
    half_list(list_head);
    return 0;
}