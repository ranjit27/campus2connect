#include <iostream>
#include <list>
using namespace std;

void splitCircularList(list<int>& clist, list<int>& first, list<int>& second) {
    
int n = clist.size();

    auto it = clist.begin();
    for (int i = 0; i < n / 2 ; ++i, ++it)
        first.push_back(*it);

 int n1= first.size();
    
    if (n % 2 != 0) {
        first.push_back(10);
        
    }
    for (; it != clist.end(); ++it)
        second.push_back(*it);
}

void display(const list<int>& lst, const string& name) {
    cout << name << ": ";
    for (int x : lst)
        cout << x << " -> ";
    cout << "(looped)\n";
}

int main() {
    list<int> clist = {10, 20, 30, 40, 50}; // odd number of elements

    list<int> firstHalf, secondHalf;

    splitCircularList(clist, firstHalf, secondHalf);

    display(firstHalf, "First Half");
    display(secondHalf, "Second Half");

    return 0;
}