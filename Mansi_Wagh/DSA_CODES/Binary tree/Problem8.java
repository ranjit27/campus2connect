import java.util.*;

public class Problem8 {
    public static int findSize(Node root)
    {
        if(root == null)
        {
            return 0;
        }

        return 1 + findSize(root.left) + findSize(root.right);
    }
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        
        // Insert nodes into the binary tree
        tree.insert(1);
        tree.insert(2);
        tree.insert(3);
        tree.insert(4);
        tree.insert(5);

        int res = findSize(tree.root);
        
        // Print inorder traversal of the binary tree
        System.out.println("Size of the binary tree:"+res);

    }    
}
