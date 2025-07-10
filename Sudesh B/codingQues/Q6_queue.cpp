#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k) {
    if (q.empty() || k > q.size() || k <= 0)
        return;

    stack<int> st;

    for (int i = 0; i < k; ++i) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    int rem = q.size() - k;
    for (int i = 0; i < rem; ++i) {
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    for (int i = 10; i <= 90; i += 10)
        q.push(i);

    int k = 4;

    cout << "Original Queue: ";
    printQueue(q);

    reverseFirstK(q, k);

    cout << "Modified Queue (first " << k << " reversed): ";
    printQueue(q);

    return 0;
}
