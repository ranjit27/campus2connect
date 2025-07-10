import java.util.Scanner;

class MyStack {
    int top = -1;
    int size;
    int[] arr;

    MyStack(int size) {
        this.size = size;
        arr = new int[size];
    }

    boolean isEmpty() {
        return top == -1;
    }

    void push(int val) {
        if (top < size - 1) {
            arr[++top] = val;
        } else {
            System.out.println("Stack Overflow");
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            System.out.println("Stack Underflow");
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            return -1;
        }
    }

    void printStack() {
        for (int i = 0; i <= top; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}

public class reversestack {

    public static void insertAtBottom(MyStack stack, int value) {
        if (stack.isEmpty()) {
            stack.push(value);
            return;
        }

        int temp = stack.pop();
        insertAtBottom(stack, value);
        stack.push(temp);
    }

    public static void reverse(MyStack stack) {
        if (stack.isEmpty()) {
            return;
        }

        int temp = stack.pop();
        reverse(stack);
        insertAtBottom(stack, temp);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        MyStack stack = new MyStack(n);

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            stack.push(val);
        }

        System.out.print("Original Stack: ");
        stack.printStack();

        reverse(stack);

        System.out.print("Reversed Stack: ");
        stack.printStack();
    }
}
