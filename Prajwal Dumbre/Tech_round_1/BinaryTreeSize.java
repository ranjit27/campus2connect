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

    int getSize(Node node) {
        if (node == null)
            return 0;
        return 1 + getSize(node.left) + getSize(node.right);
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(10);
        tree.root.left = new Node(20);
        tree.root.right = new Node(30);
        tree.root.left.left = new Node(40);
        tree.root.left.right = new Node(50);

        System.out.println("Size of the tree: " + tree.getSize(tree.root)); // Output: 5
    }
}
