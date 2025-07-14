/*Given an array of characters formed with a’s and b’s. The string is marked with special character X which represents the middle of the list (for example: ababa...ababXbabab baaa). Check whether the string is palindrome.*/

#include<iostream>
#include<conio.h>
using namespace std;

class Check {
   public:
    bool check_palindrome(string s)
    {
        int i=0,j;
        int n=s.length();
     j=n-1;
     int mid=n/2;
     if(s[mid]!='X' || n/2 ==0)
     {
        cout<<"string doesnt contain X in middle";
        return false;
     }

else{
        while(i<mid && j>mid)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else{
                cout<<"string is not a palindrome";
                return false;
                
            }
            
        }
        cout<<"String is a palindrome";
        return true;
    }
    }
};
 int main(){
    Check c;
    string s;
    cout<<"enter a string";
    cin>>s;
    c.check_palindrome(s);
 }