#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(const string& s) {
    int i = 0, j = s.length() - 1;

    while (i < j) {
        if (s[i] == 'X') {
            i++;
            continue;
        }
        if (s[j] == 'X') {
            j--;
            continue;
        }
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    string str = "ababaXbabab";
    string str1 = "abcXdef";

    if (checkPalindrome(str)) {
        cout << str << " is a palindrome.\n";
    } else {
        cout << str << " is not a palindrome.\n";
    }

    if (checkPalindrome(str1)) {
        cout << str1 << " is a palindrome.\n";
    } else {
        cout << str1 << " is not a palindrome.\n";
    }

    return 0;
}
