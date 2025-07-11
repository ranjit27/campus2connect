import java.util.*;

class Node{
    int val;
    Node next;
    public Node(int val){
        this.val = val;
        this.next = null;
    }
}




public class pallindrome_linked_list {

    static Node mid(Node head){
        Node s;
        Node f;
        s = f = head;

        while (f != null && f.next!= null) {
            s = s.next;
            f = f.next.next;
        }

        return s;
    }

    static Node reverseList(Node head){
        Node pr = null;
        while (head!= null) {
            Node next = head.next;
            head.next = pr;
            pr = head;
            head = next;

        }

        return pr;
    }
    static boolean checkPallindrome(Node head){
        Node h1 = head;
        Node h2 = mid(head);
        Node h = reverseList(h2);

        while (h!= null) {
            if(h1.val != h.val){
                return false;
            }

            h1 = h1.next;
            h = h.next;
        }
        return true;
    }
    public static void main(String[] args) {
        Node head = new Node(0);
        Node n2 = new Node(1);
        Node n3 = new Node(2);
        Node n4 = new Node(1);
        Node n5 = new Node(1);
        // Node n6 = new Node(1);

        head.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n5;
        // n5.next = n6;

        System.out.println(checkPallindrome(head));
    }
}
