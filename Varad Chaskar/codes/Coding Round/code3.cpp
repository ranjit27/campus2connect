#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data1, Node* next1)
        {
            data = data1;
            next = next1;
        }

        Node(int data1)
        {
            data = data1;
            next = nullptr;
        }
};

Node* reverseLinkLis(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* newHead = reverseLinkLis(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalfStart = reverseLinkLis(slow->next);
    Node* firstHalf = head;
    Node* secondHalf = secondHalfStart;
    bool palindrome = true;

    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    slow->next = reverseLinkLis(secondHalfStart);
    return palindrome;
}


void printLinkLis(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    if (isPalindrome(head))
        cout<<"palindrome"<< endl;
    else
        cout <<"not palindrome" << endl;

    cout <<endl;
    return 0;
}

