#include <iostream>
using namespace std;

bool isPalindrome(const string& s) {
    int mid = -1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'X') {
            mid = i;
            break;
        }
    }

    if (mid == -1) {
        cout << "No 'X' found.\n";
        return false;
    }

    int left = mid - 1;
    int right = mid + 1;

    while (left >= 0 && right < s.length()) {
        if (s[left] != s[right])
            return false;
        left--;
        right++;
    }

    return (left < 0 && right == s.length());
}

int main() {
    string s ;
    cout<<"Enter the string : \n";
    cin>>s;
    

    if (isPalindrome(s))
        cout << "Palindrome \n";
    else
        cout << "Not a palindrome \n";

    return 0;
}
