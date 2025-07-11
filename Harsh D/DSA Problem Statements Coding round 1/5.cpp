
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

void reverseStack(stack<int> st){

    if(st.empty()){
        return;
    }

    stack<int> temp;

    while(!st.empty()){

        temp.push(st.top());
        st.pop();
    }

    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }
}

int main(){
    stack<int> st;

    st.push(11);
    st.push(21);
    st.push(51);
    st.push(101);

    reverseStack(st);

    return 1;
}