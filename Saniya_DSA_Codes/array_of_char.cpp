#include<iostream>
#include<vector>

using namespace std;

bool ispalindrome(vector<char>& arr)
{
    int i=0;
    while(arr[i]!='X') i++;
    int left = i-1;
    int right = i+1;

    while(left >=0 && right < arr.size())
    {
        if(arr[left] != arr[right])
        {
            return false;
        }
        left--;
        right++;
    }
    return true;
}

int main()
{
    vector<char> arr={'a','b','a','b','X','b','a','b','a'};
    if(ispalindrome(arr))
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
}
