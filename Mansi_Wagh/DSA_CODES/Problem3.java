
// program to find if linked list is palindrome or not
import java.util.*;

class Node {
    char data;
    Node next;

    Node(char data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {

    Node head;

    public void add(char data)
    {
        if(head == null)
        {
            head = new Node(data);
            return;
        }

        Node temp = head;

        while(temp.next != null)
        {
            temp = temp.next;
        }

        temp.next = new Node(data);

    }
}

public class Problem3 {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.add('A');
        list.add('X');
        list.add('B');
        list.add('A');

        String res = "";

        Node temp = list.head;

        while(temp != null)
        {
            res += temp.data;
            temp = temp.next;
        }

        String reverseString = new StringBuilder(res).reverse().toString();

        if(res.equals(reverseString))
        {
            System.out.println("The linked list is a palindrome.");
        } else {
            System.out.println("The linked list is not a palindrome.");
        }

    }
  }
