#include<iostream>
#include<string>
using namespace std;
int main(){
string s;

cin>>s;

int i=0,j=s.size()-1;

while(s[i]!='X')i++;

j=i+1;

i--;

bool isP=true;

while(i>=0&&j<s.size()){

if(s[i]!=s[j]){

isP=false;

break;

}

i--;
j++;

}

if(isP)cout<<"Palindrome"<<endl;

else cout<<"Not Palindrome"<<endl;

return 0;
}
