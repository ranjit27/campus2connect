#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string str) {
    int mid= str.find('X');
    if (mid == 0 || mid == str.length()-1)
    {
        return false;
    }
    int left = mid - 1;
    int right = mid + 1;
    while (left >= 0 && right < str.length()) {
        if (str[left] != str[right]) {
            return false;
        }
        left--;
        right++;
    }
    return (left == -1 && right == str.length());
}

int main() {
    string str;
    cin>>str;

    if (isPalindrome(str))
        cout << "palindrome" << endl;
    else
        cout << "not palindrome" << endl;
    return 0;
}
