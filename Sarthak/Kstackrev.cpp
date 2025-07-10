#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){

int n,k;
cin>>n>>k;

queue<int>q;

for(int i=0;i<n;i++){

int x;cin>>x;q.push(x);

}

stack<int>s;

for(int i=0;i<k;i++){

s.push(q.front());q.pop();

}

while(!s.empty()){

q.push(s.top());s.pop();

}

for(int i=0;i<n-k;i++){

q.push(q.front());q.pop();

}

while(!q.empty()){

cout<<q.front()<<" ";q.pop();

}

cout<<endl;

return 0;

}