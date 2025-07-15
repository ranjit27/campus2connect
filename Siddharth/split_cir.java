

class Node{
    int data;
    Node next; 
    
    Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class split_cir {

    public static void split_Cir(Node head, Node[] head1, Node[] head2){
        if(head == null || head.next == head) {
            head1[0] = head;
            head2[0] = null;
            return;

        }

        Node slow = head;
        Node fast = head;

        while(fast.next != head && fast.next.next != head){
            slow = slow.next;
            fast = fast.next.next;
        }

        if (fast.next.next == head) {
            fast = fast.next;
        }

        head1[0] = head;
        head2[0] = slow.next;

        slow.next = head1[0];
        fast.next = head2[0];

    }

    public static void printCircularList(Node head){
        if (head == null) return;
        Node temp = head;
        do{
            System.out.print(temp.data+" ");
            temp = temp.next;
        }while(temp != head);
        System.out.println();
        }
    

    public static void main(String[] args) {

        Node head = new Node(1);
        head.next  = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);
        head.next.next.next.next.next = head;

        Node[] head1 = new Node[1];
        Node[] head2 = new Node[1];
        split_Cir(head, head1, head2);

        System.out.println("First Circular Linked List:");
        printCircularList(head1[0]);

        System.out.println("Second Circular Linked List:");
        printCircularList(head2[0]);
        
    }
    
}
