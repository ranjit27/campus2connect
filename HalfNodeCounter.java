import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

class Queue {
    Node[] arr;
    int front, rear, size;

    Queue(int capacity) {
        arr = new Node[capacity];
        front = rear = size = 0;
    }

    boolean isEmpty() {
        return size == 0;
    }

    void enqueue(Node node) {
        if (size == arr.length) return;
        arr[rear++] = node;
        size++;
    }

    Node dequeue() {
        if (isEmpty()) return null;
        size--;
        return arr[front++];
    }
}

public class HalfNodeCounter {

    static Node root;

    public static void insert(int val) {
        Node newNode = new Node(val);
        if (root == null) {
            root = newNode;
            return;
        }

        Queue queue = new Queue(100);
        queue.enqueue(root);

        while (!queue.isEmpty()) {
            Node temp = queue.dequeue();

            if (temp.left == null) {
                temp.left = newNode;
                break;
            } else {
                queue.enqueue(temp.left);
            }

            if (temp.right == null) {
                temp.right = newNode;
                break;
            } else {
                queue.enqueue(temp.right);
            }
        }
    }

    public static int countHalfNodes(Node node) {
        if (node == null)
            return 0;

        Queue queue = new Queue(100);
        queue.enqueue(node);
        int count = 0;

        while (!queue.isEmpty()) {
            Node temp = queue.dequeue();

            if ((temp.left == null && temp.right != null) || (temp.left != null && temp.right == null)) {
                count++;
            }

            if (temp.left != null)
                queue.enqueue(temp.left);

            if (temp.right != null)
                queue.enqueue(temp.right);
        }

        return count;
    }

    public static void inorder(Node node) {
        if (node == null)
            return;
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        System.out.println("Enter " + n + " values:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            insert(val);
        }

        System.out.print("Inorder Traversal: ");
        inorder(root);
        System.out.println();

        int halfNodeCount = countHalfNodes(root);
        System.out.println("Number of half nodes: " + halfNodeCount);
    }
}
