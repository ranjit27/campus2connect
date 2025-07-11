class Node {
    int data;
    Node next;
    
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class CircularLinkedListSplit {
    
    Node head;

   
    void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            head.next = head; // circular link
        } else {
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = head;
        }
    }

  
    void splitList() {
        Node slow = head;
        Node fast = head;

      
        while (fast.next != head && fast.next.next != head) {
            slow = slow.next;
            fast = fast.next.next;
        }
      
        if (fast.next.next == head) {
            fast = fast.next;
        }
        
        Node head1 = head;
        Node head2 = slow.next;

        
        slow.next = head1;
        
        fast.next = head2;
        System.out.print("First Half: ");
        printList(head1);

        System.out.print("Second Half: ");
        printList(head2);
    }
    void printList(Node node) {
        Node temp = node;
        if (node != null) {
            do {
                System.out.print(temp.data + " ");
                temp = temp.next;
            } while (temp != node);
            System.out.println();
        }
    }

    public static void main(String[] args) {
        CircularLinkedListSplit cll = new CircularLinkedListSplit();

       
        cll.insert(1);
        cll.insert(2);
        cll.insert(3);
        cll.insert(4);
        cll.insert(5); 
        cll.splitList();
    }
}
