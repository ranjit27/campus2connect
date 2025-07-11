#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

void displayFromEnd(ListNode* head) {
    if (head == nullptr) return;
    displayFromEnd(head->next);
    cout << head->val << " ";
}

int main() {
    ListNode LN1, LN2;

    LN1.val = 15;
    LN2.val = 20;

    LN1.next = &LN2;
    LN2.next = nullptr;

    ListNode* head = &LN1;

    cout << "Linked List from end: ";
    displayFromEnd(head);
    cout << endl;

    return 0;
}
