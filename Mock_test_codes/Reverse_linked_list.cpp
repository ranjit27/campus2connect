


Node* rList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

void printReverse(Node* head) {
    Node* rHead= rList(head);
    Node* current = rHead;
    
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    
    
    rList(rHead);
}


