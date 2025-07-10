//
// Created by Anish Sapre on 10/07/25.
//
#include <stack>
#include <iostream>

using namespace std;

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void reverseStack(stack<int> s) {
    if (s.empty()) {
        return;
    }
    stack<int> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    cout << "Reversed Stack: ";
    printStack(temp);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Stack: ";
    printStack(s);
    reverseStack(s);

    return 0;
}
