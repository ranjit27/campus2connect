#include <iostream>
#include <queue>
using namespace std;

void moveKToEnd(queue<int>& q, int k) {
    if (k == 0) return;

    int front = q.front();
    q.pop();

    moveKToEnd(q, k - 1);
    q.push(front);
}

queue<int> reverseFirstK(queue<int> q, int k) {
    moveKToEnd(q, k);

    int remaining = q.size() - k;
    while (remaining--) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    int n, k;

    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << "Enter value of k: ";
    cin >> k;

    if (k > n || k < 0) {
        cout << "Invalid value of k.\n";
        return 1;
    }

    q = reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements:\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
