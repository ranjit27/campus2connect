import java.util.Queue;
import java.util.LinkedList;

class Node{
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

    public void insert(int key)
    {
        Node newNode = new Node(key);

        if(root == null)
        {
            root = newNode;
            return;
        }

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        while(!queue.isEmpty())
        {
            Node temp = queue.poll();

            if(temp.left == null)
            {
                temp.left = newNode;
                return;
            }
            else{
                queue.add(temp.left);
            }

            if(temp.right == null)
            {
                temp.right = newNode;
                return;
            }
            else{
                queue.add(temp.right);
            }
        }
    }

    public void inorder(Node root)
    {
        if(root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }
}

// Write an algorithm and code for  inserting an element into binary tree.
public class Problem7 {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();

        tree.insert(10);
        tree.insert(20);
        tree.insert(30);
        tree.insert(40);
        tree.insert(50);

        System.out.print("Inorder traversal of the tree: ");
        tree.inorder(tree.root);
    }
}
