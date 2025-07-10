 import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class BinaryTreeSizeSimple {

    public static Node buildTree(Scanner scanner) {
        System.out.print("Enter node value (-1 for no node): ");
        int value = scanner.nextInt();
        
        if (value == -1) {
            return null;  // No node
        }
        
        Node newNode = new Node(value);
        
        System.out.println("Enter left child of " + value);
        newNode.left = buildTree(scanner);
        
        System.out.println("Enter right child of " + value);
        newNode.right = buildTree(scanner);
        
        return newNode;
    }

    public static int size(Node root) {
        if (root == null) {
            return 0;
        } else {
            return 1 + size(root.left) + size(root.right);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Build your binary tree:");
        Node root = buildTree(scanner);
        
        int treeSize = size(root);
        System.out.println("Size of the binary tree: " + treeSize);
        
        scanner.close();
    }
} 
