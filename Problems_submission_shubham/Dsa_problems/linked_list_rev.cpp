#include <iostream>
#include <list>
using namespace std;


bool is_pallindrome(list<int>& clist) {
   
    
auto it1 = (clist.begin() ) ;
auto it2 = (clist.end() ) ;
it2--; 
for (int i =0 ; i< clist.size() ; i++)
{
    // it -- ; 
    // cout<< *(it)<<" ";
    if (*(it1 ) == (*it2))
    {
        it1 ++;
        it2 --;
    }
    else{
            return false;
        }
    
}
 return true;
   
}


int main() {
    list<int> clist = {10, 20,  20, 10}; 
if(is_pallindrome(clist)) {
    cout << "YES" << endl;
} else {
    cout << "NO" << endl;
}
    return 0;
}