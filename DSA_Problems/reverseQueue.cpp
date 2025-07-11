#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    if (k <= 0 || k > q.size())
        return q;

    stack<int> st;

    // Push k elements 
    for (int i = 0; i < k; ++i) {
        st.push(q.front());
        q.pop();
    }

    // Enqueue back
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Move remaining ele
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; ++i) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 5; ++i) {
        q.push(i);
    }

    int k = 3;
    queue<int> result = reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}

