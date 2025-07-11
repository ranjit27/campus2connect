

void reverseStack(stack<int>& s) {
    stack<int> temp1, temp2;
    
    
    while (!s.empty()) {
        temp1.push(s.top());
        s.pop();
    }
    
   
    while (!temp1.empty()) {
        temp2.push(temp1.top());
        temp1.pop();
    }
    
    
    while (!temp2.empty()) {
        s.push(temp2.top());
        temp2.pop();
    }
}

