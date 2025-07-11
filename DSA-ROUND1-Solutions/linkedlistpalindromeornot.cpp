#include <iostream>
#include <stack>
using namespace std;

class box
{
public:
    char ch;
    box *next;

    box(char c)
    {
        ch = c;
        next = NULL;
    }
};

void add(box* &start, char c)
{
    box* newone = new box(c);

    if (start == NULL)
    {
        start = newone;
        return;
    }

    box* t = start;
    while (t->next != NULL)
    {
        t = t->next;
    }

    t->next = newone;
}

void show(box* start)
{
    while (start != NULL)
    {
        cout << start->ch << " ";
        start = start->next;
    }
    cout << endl;
}

bool checkpal(box* start)
{
    stack<char> s;
    box* t = start;

    while (t != NULL)
    {
        s.push(t->ch);
        t = t->next;
    }

    t = start;
    while (t != NULL)
    {
        if (t->ch != s.top())
        {
            return false;
        }
        s.pop();
        t = t->next;
    }

    return true;
}

int main()
{
    box* start = NULL;
    int n;
    char c;

    cout << "how many characters? ";
    cin >> n;

    cout << "enter " << n << " characters:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        add(start, c);
    }

    cout << "\nlist is: ";
    show(start);

    if (checkpal(start))
    {
        cout << "yes, it's palindrome\n";
    }
    else
    {
        cout << "no, not palindrome\n";
    }

    return 0;
}