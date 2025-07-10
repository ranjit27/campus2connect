
#include <iostream>
#include<stack>
using namespace std;
void transfer(stack<int>& s1, stack<int>& s2, int n)
{
    for (int i = 0; i < n; i++) {
        int temp = s1.top(); 
        s1.pop();
        s2.push(temp);
    }
}

void reverse_stack(stack<int>& s, int n)
{
    stack<int> s2;

    for (int i = 0; i < n; i++) {

        int x = s.top();
        s.pop();
        transfer(s, s2, n - i - 1);
        s.push(x);
        transfer(s2, s, n - i - 1);
    }
}

int main()
{
    int n = 5;

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverse_stack(s, n);

    for (int i = 0; i < n; i++) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}