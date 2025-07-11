#include<iostream>
#include<stack>
using namespace std;

void reverse(stack<int> st)
{
    stack<int> helper;

    while(!st.empty())
    {
        int topE = st.top();
        st.pop();

        // move everything from helper to st
        while(!helper.empty())
        {
            st.push(helper.top());
            helper.pop();
        }

        // push topE into helper (acts like inserting at bottom)
        helper.push(topE);

        // move everything back from st to helper
        while(!st.empty())
        {
            helper.push(st.top());
            st.pop();
        }
    }

    while(!helper.empty())
    {
        cout << helper.top() << " ";
        helper.pop();
    }
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    reverse(st);
}
