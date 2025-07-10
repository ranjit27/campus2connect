#include <bits/stdc++.h>
using namespace std;



int main(){
// Node n = new Node();
list<int> my_list ;
my_list.push_back(10);
my_list.push_back(20);
my_list.push_back(30);
my_list.push_back(40);
my_list.push_back(50);

auto it = (my_list.end() ) ;
for (int i =0 ; i< my_list.size() ; i++)
{
    it -- ; 
    cout<< *(it)<<" ";
}
}