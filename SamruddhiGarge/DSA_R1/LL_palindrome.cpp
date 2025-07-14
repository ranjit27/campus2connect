#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Insert node at end
void insert_node(int data) {
    Node* new_node = new Node{data, nullptr};
    if (!head) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = new_node;
    }
}

// Reverse linked list
Node* reverse(Node* node) {
    Node* prev = nullptr;
    Node* current = node;
    while (current) {
        Node* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}

// Check if palindrome
bool is_palindrome(Node* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle
    Node* slow = head;
    Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* second_half = reverse(slow->next);

    // Step 3: Compare halves
    Node* first_half = head;
    Node* temp = second_half;
    bool result = true;

    while (temp) {
        if (first_half->data != temp->data) {
            result = false;
            break;
        }
        first_half = first_half->next;
        temp = temp->next;
    }

    // Step 4 (optional): Restore list
    slow->next = reverse(second_half);

    return result;
}

// Print list
void print_list(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert_node(val);
    }

    cout << "Linked List: ";
    print_list(head);

    if (is_palindrome(head))
        cout << "The linked list is a palindrome.\n";
    else
        cout << "The linked list is NOT a palindrome.\n";

    return 0;
}
