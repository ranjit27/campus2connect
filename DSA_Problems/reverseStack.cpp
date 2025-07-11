#include <iostream>
#include <stack>
using namespace std;

int removeBottom(stack<int>& st) {
    if (st.size() == 1) {
        int bottom = st.top();
        st.pop();
        return bottom;
    }

    int topElement = st.top();
    st.pop();

    int bottomElement = removeBottom(st);

    st.push(topElement); 
    return bottomElement;
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int bottomElement = removeBottom(st);

    reverseStack(st);

    st.push(bottomElement);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original stack : ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(st);

    cout << "Reversed stack : ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
