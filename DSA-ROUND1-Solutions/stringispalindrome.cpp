#include <iostream>
#include <vector>
using namespace std;

bool checkpalindrome(vector<char> arr)
{
    int mid = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 'X')
        {
            mid = i;
            break;
        }
    }

    if (mid == -1)
    {
        return false;
    }

    int i = mid - 1;
    int j = mid + 1;

    while (i >= 0 && j < arr.size())
    {
        if (arr[i] != arr[j])
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

int main()
{
    int n;
    char ch;
    vector<char> str;

    cout << "enter total characters (including X): ";
    cin >> n;

    cout << "enter " << n << " characters:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        str.push_back(ch);
    }

    cout << "\nentered string: ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    if (checkpalindrome(str))
    {
        cout << "it is a palindrome\n";
    }
    else
    {
        cout << "not a palindrome\n";
    }

    return 0;
}