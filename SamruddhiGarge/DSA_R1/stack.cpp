#include <iostream>
#include<conio.h>
using namespace std;

struct Node
 {
    int data;
    Node* next;
};

class Stack
 {
private:
    Node* top;

public:
    Stack() 
    {
        top = nullptr;
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }

    void push(int value) 
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop()
     {
        if (isEmpty())
         {
            cout << "Stack Underflow!\n";
            return -1;
        }

        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    void display()
     {
        if (isEmpty())
         {
            cout << "Stack is empty.\n";
            return;
        }

        Node* temp = top;
        cout << "Stack (top to bottom): ";
        while (temp != nullptr) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    void printReversed(Node* node)
     {
        if (node == nullptr) return;
        printReversed(node->next);
        cout << node->data << " ";
    }

    void printFromBottom() 
    {
        cout << "Stack (bottom to top): ";
        printReversed(top);
        cout << endl;
    }
};

void insertAtBottom(Stack& st, int value) 
{
    if (st.isEmpty()) {
        st.push(value);
        return;
    }

    int temp = st.pop();
    insertAtBottom(st, value);
    st.push(temp);
}

void reverseStack(Stack& st)
 {
    if (st.isEmpty()) return;

    int temp = st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
}

int main()
 {
    Stack st;
    int n, val;

    cout << "Enter number of elements to push into stack: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i)
     {
        cin >> val;
        st.push(val);
    }

    cout << "\nOriginal Stack:\n";
    st.display();
    st.printFromBottom(); // Extra for clarity

    reverseStack(st);

    cout << "\nAfter Reversing Stack:\n";
    st.display();
    st.printFromBottom(); // Now reversed
    return 0;
}
