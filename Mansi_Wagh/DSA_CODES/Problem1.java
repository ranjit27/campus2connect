//display a Linked List from the end
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    // add new node at the end
    public void add(int data)
    {
        Node newNode = new Node(data);

        // if linked list is empty
        if(head == null)
        {
            head = newNode;
            return;
        }
        
        Node current = head;
        while(current.next != null)
        {
            current = current.next;
        }

        current.next = newNode;
    }

    public void display()
    {
        Node curr = head;
        while(curr != null)
        {
            System.out.println(curr.data);
            curr = curr.next;
        }
    }

    public void reverseLinkedList()
    {
        Node prev = null;
        Node curr = head;
        Node next;

        while(curr != null)
        {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
}

public class Problem1 {

    public static void main(String[] args)
    {
        LinkedList list = new LinkedList();
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);

        System.out.println("Original linked list : ");
        list.display();

        list.reverseLinkedList();

        System.out.println("Reversed linked list : ");
        list.display();

        
    }
}