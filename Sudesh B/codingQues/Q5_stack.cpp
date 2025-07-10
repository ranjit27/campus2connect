#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int>& st, int value) {
    if (st.empty()) {
        st.push(value);
        return;
    }

    int top = st.top();
    st.pop();
    insert(st, value);
    st.push(top);
}

void reverseStack(stack<int>& st) {
    if (st.empty())
        return;

    int top = st.top();
    st.pop();
    reverseStack(st);
    insert(st, top);
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

    cout << "Original Stack : ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed Stack : ";
    printStack(st);

    return 0;
}
