#include <bits/stdc++.h>
#include <list>
using namespace std;

void display(stack<int> s1) {
    cout << "\nTop to bottom \n";
    while (!s1.empty()) {
        
        cout << s1.top() << "-";
        s1.pop();
    }
    
}

stack<int> rev( stack<int> s1, stack<int> s2) {
    while (!s1.empty()) {
        
        s2.push(s1.top());
        s1.pop();
    }
    return s2;
}
int main() {
    stack<int> s1;
    stack<int> s2;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    
    display(s1);
    s2 = rev(s1, s2);
    cout<<"\n After reverse ";
    display(s2);
    
}