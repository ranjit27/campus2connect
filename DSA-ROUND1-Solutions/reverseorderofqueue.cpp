#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reversefirstk(queue<int> &q, int k)
{
    if(q.empty() || k<=0 || k > q.size())
    {
        return;
    }

    stack<int> s;

    for(int i=0; i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    int left = q.size() - k;

    while(left--)
    {
        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    int n, val, k;

    cout<<"how many values? ";
    cin>>n;

    cout<<"enter "<<n<<" numbers:\n";
    for(int i=0; i<n; i++)
    {
        cin>>val;
        q.push(val);
    }

    cout<<"enter value of k: ";
    cin>>k;

    cout<<"\nqueue before reverse: ";
    display(q);

    reversefirstk(q, k);

    cout<<"queue after reverse: ";
    display(q);

    return 0;
}