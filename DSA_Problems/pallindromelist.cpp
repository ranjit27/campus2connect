#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

bool palindromeStack(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    stack<int> st;
    ListNode* current = head;

    while (current != nullptr) {
        st.push(current->val);
        current = current->next;
    }
    current = head;
    while (current != nullptr) {
        if (st.top() != current->val)
            return false;
        st.pop();
        current = current->next;
    }

    return true;
}

int main() {
    
    ListNode n1{1}, n2{2}, n3{3}, n4{1};
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = nullptr;

    if (palindromeStack(&n1))
        cout << "list is a palindrome." << endl;
    else
        cout << "The list is not a palindrome." << endl;

    return 0;
}
