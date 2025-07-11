import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

    int countHalfNodes() {
        if (root == null)
            return 0;

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        int count = 0;

        while (!queue.isEmpty()) {
            Node current = queue.poll();

            boolean hasLeft = current.left != null;
            boolean hasRight = current.right != null;

            if ((hasLeft && !hasRight) || (!hasLeft && hasRight))
                count++;

            if (hasLeft)
                queue.add(current.left);
            if (hasRight)
                queue.add(current.right);
        }

        return count;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(10);
        tree.root.left = new Node(20);
        tree.root.right = new Node(30);
        tree.root.left.left = new Node(40);
        tree.root.right.right = new Node(50);

        System.out.println("Number of half nodes: " + tree.countHalfNodes()); // Output: 2
    }
}
