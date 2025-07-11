import java.util.Queue;
import java.util.LinkedList;

//Write an algorithm and code for finding the number of half nodes (nodes with only one child) in the binary tree without using recursion.

class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

  

    // Count half nodes (nodes with only one child) without recursion
    public int countHalfNodes() {
        if (root == null) return 0;
        int count = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node temp = queue.poll();
            if ((temp.left == null && temp.right != null) || (temp.left != null && temp.right == null)) {
                count++;
            }
            if (temp.left != null) queue.add(temp.left);
            if (temp.right != null) queue.add(temp.right);
        }
        return count;
    }
}

public class Problem9 {

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();

         // Constructing the binary tree
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.right = new Node(4);  // half node
        tree.root.right.left = new Node(5);
        tree.root.right.right = new Node(6);
        tree.root.right.left.left = new Node(7);  // half node

        System.out.println("Number of half nodes: " + tree.countHalfNodes());

    }
}
