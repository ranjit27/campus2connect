// Java program to reverse the first K elements of a queue
public class ReverseKInQueue {

    
    static class MyQueue {
        int[] arr;
        int front, rear, size, capacity;

        MyQueue(int capacity) {
            this.capacity = capacity;
            arr = new int[capacity];
            front = 0;
            rear = -1;
            size = 0;
        }

        boolean isEmpty() {
            return size == 0;
        }

        boolean isFull() {
            return size == capacity;
        }

        void enqueue(int data) {
            if (isFull()) {
                System.out.println("Queue is full");
                return;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = data;
            size++;
        }

        int dequeue() {
            if (isEmpty()) {
                System.out.println("Queue is empty");
                return -1;
            }
            int data = arr[front];
            front = (front + 1) % capacity;
            size--;
            return data;
        }

        void display() {
            int count = size;
            int i = front;
            while (count-- > 0) {
                System.out.print(arr[i] + " ");
                i = (i + 1) % capacity;
            }
            System.out.println();
        }
    }

 
    static class MyStack {
        int[] stack;
        int top = -1;
        int capacity;

        MyStack(int capacity) {
            this.capacity = capacity;
            stack = new int[capacity];
        }

        void push(int data) {
            if (top == capacity - 1) {
                System.out.println("Stack Overflow");
                return;
            }
            stack[++top] = data;
        }

        int pop() {
            if (top == -1) {
                System.out.println("Stack Underflow");
                return -1;
            }
            return stack[top--];
        }

        boolean isEmpty() {
            return top == -1;
        }
    }

  
    static void reverseFirstKElements(MyQueue queue, int k) {
        if (queue.size < k || k < 0) {
            System.out.println("Invalid k");
            return;
        }

        MyStack stack = new MyStack(k);


        for (int i = 0; i < k; i++) {
            stack.push(queue.dequeue());
        }

        int[] temp = new int[queue.capacity];
        int idx = 0;

        while (!stack.isEmpty()) {
            temp[idx++] = stack.pop();
        }

        int remaining = queue.size;
        for (int i = 0; i < remaining; i++) {
            temp[idx++] = queue.dequeue();
        }

        for (int i = 0; i < idx; i++) {
            queue.enqueue(temp[i]);
        }
    }

    public static void main(String[] args) {
        MyQueue queue = new MyQueue(20);
        int[] data = {10, 20, 30, 40, 50, 60, 70, 80, 90};
        for (int x : data) {
            queue.enqueue(x);
        }

        int k = 4;

        System.out.println("Original Queue:");
        queue.display();

        reverseFirstKElements(queue, k);

        System.out.println("Queue after reversing first " + k + " elements:");
        queue.display();
    }
}