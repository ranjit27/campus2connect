#include <bits/stdc++.h>
#include <list>
using namespace std;

void display(queue<int> q1) {
     while (!q1.empty())
    {
        cout<<q1.front() <<"-" ;
        q1.pop();
    }
}
int main() {
    queue <int> q1;
    queue <int> q2;
    stack <int> s;
    int n; 
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    //display
    display(q1);
    
    cout<<"\n Enter n ";
    cin>> n ;

    //push to stack
        for(int i=0;i<n;i++)
        {
            s.push(q1.front());
            q1.pop();
        }
        //pop from stack
        for(int i=0;i<n;i++)
        {
            q2.push(s.top());
            s.pop();
        }
    while (!q1.empty())
    {
        
        //all remaining
        q2.push(q1.front());
        q1.pop();
    }
   display(q2) ;
    
    
 return 0;
}