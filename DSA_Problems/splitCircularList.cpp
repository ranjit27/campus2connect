#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

pair<ListNode*, ListNode*> splitCircularList(ListNode* head) {
    if (head == nullptr || head->next == head) {
        return {head, nullptr};
    }

    ListNode* current = head;
    int length = 1;
    while (current->next != head) {
        current = current->next;
        length++;
    }

    int firstHalfSize = (length + 1) / 2;

    current = head;
    for (int i = 1; i < firstHalfSize; ++i) {
        current = current->next;
    }

    ListNode* secondHead = current->next;
    current->next = head;

    ListNode* temp = secondHead;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = secondHead;

    return {head, secondHead};
}

int main() {
    ListNode n1{10}, n2{20}, n3{30}, n4{40}, n5{50};
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5; n5.next = &n1;

    auto result = splitCircularList(&n1);
    auto print = [](ListNode* head) {
        if (!head) return;
        ListNode* temp = head;
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    };

    cout << "first Half: ";
    print(result.first);

    cout << "second Half: ";
    print(result.second);

    return 0;
}

