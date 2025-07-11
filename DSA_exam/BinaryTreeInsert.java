
public class BinaryTreeInsert {

    static class Node {
        int data;
        Node left, right;

        Node(int value) {
            data = value;
            left = right = null;
        }
    }


    static class NodeQueue {
        Node[] arr;
        int front = 0, rear = 0, size = 0, capacity;

        NodeQueue(int capacity) {
            this.capacity = capacity;
            arr = new Node[capacity];
        }

        void enqueue(Node node) {
            if (size == capacity) {
                System.out.println("Queue is full");
                return;
            }
            arr[rear++] = node;
            size++;
        }

        Node dequeue() {
            if (size == 0) {
                return null;
            }
            Node temp = arr[front++];
            size--;
            return temp;
        }

        boolean isEmpty() {
            return size == 0;
        }
    }


    static void insert(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return;
        }

        NodeQueue queue = new NodeQueue(100); // Adjust size as needed
        queue.enqueue(root);

        while (!queue.isEmpty()) {
            Node temp = queue.dequeue();

            if (temp.left == null) {
                temp.left = new Node(key);
                break;
            } else {
                queue.enqueue(temp.left);
            }

            if (temp.right == null) {
                temp.right = new Node(key);
                break;
            } else {
                queue.enqueue(temp.right);
            }
        }
    }


    static void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }


    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(11);
        root.left.left = new Node(7);
        root.right = new Node(9);
        root.right.left = new Node(15);
        root.right.right = new Node(8);

        System.out.println("Inorder traversal before insertion:");
        inorder(root);

        int key = 12;
        insert(root, key);

        System.out.println("\nInorder traversal after insertion of " + key + ":");
        inorder(root);
    }
}

