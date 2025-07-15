import java.util.*;

public class HalfNodeCounter {

    static class Node {
        int data;
        Node left, right;

        Node(int value) {
            data = value;
            left = right = null;
        }
    }

    public static int countHalfNodes(Node root) {
        if (root == null) {
            return 0;
        }

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        int count = 0;

        while (!queue.isEmpty()) {
            Node current = queue.poll();

            boolean hasLeft = current.left != null;
            boolean hasRight = current.right != null;

            if ((hasLeft && !hasRight) || (!hasLeft && hasRight)) {
                count++;
            }

            if (hasLeft) {
                queue.add(current.left);
            }
            if (hasRight) {
                queue.add(current.right);
            }
        }

        return count;
    }

    public static void main(String[] args) {

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.right.right = new Node(5);

        int halfNodes = countHalfNodes(root);
        System.out.println("Number of half nodes: " + halfNodes); 
    }
}
