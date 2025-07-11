public class ReverseCustomStack {


    static class Stack {
        int top = -1;
        int size;
        int[] arr;

        Stack(int size) {
            this.size = size;
            arr = new int[size];
        }

        void push(int x) {
            if (top >= size - 1) {
                System.out.println("Stack Overflow");
                return;
            }
            arr[++top] = x;
        }

        int pop() {
            if (isEmpty()) {
                System.out.println("Stack Underflow");
                return -1;
            }
            return arr[top--];
        }

        boolean isEmpty() {
            return top == -1;
        }

        int peek() {
            if (isEmpty()) return -1;
            return arr[top];
        }

        void display() {
            for (int i = top; i >= 0; i--) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }
    }

   
    static void insertAtBottom(Stack stack, int item) {
        if (stack.isEmpty()) {
            stack.push(item);
            return;
        }
        int temp = stack.pop();
        insertAtBottom(stack, item);
        stack.push(temp);
    }

   
    static void reverseStack(Stack stack) {
        if (stack.isEmpty()) {
            return;
        }
        int temp = stack.pop();
        reverseStack(stack);
        insertAtBottom(stack, temp);
    }

    public static void main(String[] args) {
        Stack myStack = new Stack(10);

        myStack.push(1);
        myStack.push(2);
        myStack.push(3);
        myStack.push(4);

        System.out.println("Original Stack:");
        myStack.display();

        reverseStack(myStack);

        System.out.println("Reversed Stack:");
        myStack.display();
    }
}