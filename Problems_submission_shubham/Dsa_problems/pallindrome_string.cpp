#include <bits/stdc++.h>
using namespace std;


bool is_pallindrome(string s) {
    int l =0 ;
    int r = s.length()-1;
    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
// Node n = new Node();
string a;
cin>> a;
if(is_pallindrome(a)) {
    cout << "YES" << endl;
} else {
    cout << "NO" << endl;
}
}