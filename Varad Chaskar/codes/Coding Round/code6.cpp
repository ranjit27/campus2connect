#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) return;
    stack<int> st;
    for (int i = 0; i < k; ++i) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    int remaining = q.size() - k;
    for (int i = 0; i < remaining; ++i) {
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
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    for (int val : arr) {
        q.push(val);
    }

    int k = 4;
    printQueue(q);
    reverseFirstK(q, k);
    printQueue(q);
    return 0;
}
