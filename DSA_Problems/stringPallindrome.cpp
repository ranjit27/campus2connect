#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindromeWithFlag(const string& s) {
    int flagPos = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != 'a' && s[i] != 'b') {
            flagPos = i;
            break;
        }
    }
    if (flagPos == -1) {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        return s == reversed;
    }
    string leftPart = s.substr(0, flagPos);
    string rightPart = s.substr(flagPos + 1);

    reverse(rightPart.begin(), rightPart.end());
    return leftPart == rightPart;
}
bool isPalindromeWithFlagMarker(const string& s, const string& flagMarker = "(flag)") {
    size_t flagPos = s.find(flagMarker);

    if (flagPos == string::npos) {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        return s == reversed;
    }
    string leftPart = s.substr(0, flagPos);
    string rightPart = s.substr(flagPos + flagMarker.length());
    reverse(rightPart.begin(), rightPart.end());
    return leftPart == rightPart;
}



