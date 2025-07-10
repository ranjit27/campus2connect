#include<stdlib.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseKElements(queue<int>& q, int k) {
    if (q.empty() || k > q.size() || k <= 0)
        return;

    stack<int> s;

    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    int rem = q.size() - k;
    for (int i = 0; i < rem; ++i) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseKElements(q, 3);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}