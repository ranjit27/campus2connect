#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
void create(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void display_reverse(struct Node* node) {
    if (node == NULL)
        return;
    display_reverse(node->next);
    printf("%d ", node->data);
}

int main() {
    create(1);
    create(2);
    create(3);
    create(4);
    create(5);

    printf("List from end: ");
    display_reverse(head);
    printf("\n");

    return 0;
}
