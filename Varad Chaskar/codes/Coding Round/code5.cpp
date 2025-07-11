#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }

    int topElem = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(topElem);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int topElem = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElem);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "og: ";
    printStack(st);
    reverseStack(st);
    cout << "Reversed Stack: ";
    printStack(st);

    return 0;
}
