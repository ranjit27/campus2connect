// Created by Anish Sapre on 10/07/25

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverse_till_k(queue<int>& q, int k) {
    if (q.empty() || k > q.size() || k <= 0) {
        return;
    }
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

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main() {
    queue<int> q;
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    for (int i = 0; i < n; ++i) {
        q.push(arr[i]);
    }

    reverse_till_k(q, k);

    cout << "Rotated: ";
    printQueue(q);

    return 0;
}
