import java.util.*;

class Node{
    int val;
    Node next;
    public Node(int val){
        this.val = val;
        this.next = null;
    }
}


public class linked_list_reverse{

    static List<Integer> ans = new ArrayList<>();
    public static void store_arr(Node root){
        while (root!= null) {
            ans.add(0,root.val);
            root = root.next;
        }
    }
    public static void main(String[] args) {

        Node root = new Node(0);
        Node n1 = new Node(1);
        Node n2 = new Node(2);
        Node n3 = new Node(3);
        Node n4 = new Node(4);

        root.next = n1;
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        store_arr(root);

        for(int i =0; i< ans.size();i++){
            System.out.print(ans.get(i)+"->");
        }
    }
}