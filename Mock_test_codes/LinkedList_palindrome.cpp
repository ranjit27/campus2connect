// This code checks if a linked list is a palindrome using recursion.




bool checkPalindrome(Node* &left, Node* right);
bool isPalindrome(Node* head);


bool checkPalindrome(Node* &left, Node* right) {
    if (!right) return true;
    
    bool isPal = checkPalindrome(left, right->next);
    if (!isPal) return false;
    
    bool dataMatch = (left->data == right->data);
    left = left->next;
    
    return dataMatch;
}

bool isPalindrome(Node* head) {
    return checkPalindrome(head, head);
}


