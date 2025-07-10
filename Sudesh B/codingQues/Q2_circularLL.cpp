#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    if (*head_ref == nullptr) {
        *head_ref = newNode;
        newNode->next = *head_ref;
    } else {
        Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head_ref;
    }
}

void printList(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}

void splitCircularList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (head == nullptr) {
        *head1_ref = nullptr;
        *head2_ref = nullptr;
        return;
    }

    Node *slow = head, *fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    *head1_ref = head;
    *head2_ref = slow->next;

    slow->next = *head1_ref;
    fast->next = *head2_ref;
}

int main() {
    Node* head = nullptr;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50); 

    cout << "Original Circular Linked List:\n";
    printList(head);

    Node *head1 = nullptr, *head2 = nullptr;

    splitCircularList(head, &head1, &head2);
    printList(head1);
    printList(head2);

    return 0;
}
