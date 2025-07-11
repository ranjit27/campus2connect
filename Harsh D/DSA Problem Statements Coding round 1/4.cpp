
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool plalindromeString(string s){

    if(s.empty()){
        return 0;
    }

    stack<char> st;

    int i = 0;

    while(s[i] != 'X'){
        st.push(s[i]);
        i++;
    }

    i++;

    while(i < s.length()){
        if(s[i] != st.top()){
            return 0;
        }
        st.pop();
        i++;
    }

    if(st.empty()){
        return 1;
    }else{
        return 0;
    }

    return 1;
}

int main(){
    string s = "abcXcb";

    bool ret = plalindromeString(s);

    if(ret == 1){
        cout<<"Yes , it is a palindrome"<<endl;
    }
    else{
        cout<<"No , it is not a palindrome"<<endl;
    }
}