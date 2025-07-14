#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;


void insert_node(int data) {
    Node* new_node = new Node;
    new_node->data = data;

    if (head == nullptr) {
        head = new_node;
        new_node->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = head;
    }
}


void print_circular(Node* head_ref) {
    if (head_ref == nullptr) return;

    Node* temp = head_ref;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head_ref);
    cout << endl;
}

// Splitting list into two halves
void split_list(Node* head, Node** head1_ref, Node** head2_ref) {
    if (head == nullptr)
        return;

    Node* slow = head;
    Node* fast = head;

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
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        insert_node(val);
    }

    cout << "\nOriginal List: ";
    print_circular(head);

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    split_list(head, &head1, &head2);

    cout << "First half: ";
    print_circular(head1);

    cout << "Second half: ";
    print_circular(head2);

    return 0;
}
