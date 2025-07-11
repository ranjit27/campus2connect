#include <iostream>
#include <stack>
using namespace std;

void insertbottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    insertbottom(s, val);
    s.push(temp);
}

void reversestack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();
    reversestack(s);
    insertbottom(s, temp);
}

void show(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    int n, x;

    cout << "how many elements? ";
    cin >> n;

    cout << "enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }

    cout << "\noriginal stack (top to bottom): ";
    show(s);

    reversestack(s);

    cout << "reversed stack (top to bottom): ";
    show(s);

    return 0;
}