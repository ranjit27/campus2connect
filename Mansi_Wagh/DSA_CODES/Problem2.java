// Split a Circular Linked List into two equal parts. 

class CircularLinkedList {
    Node head;

    void add(int data)
    {
        Node newNode = new Node(data);
        if(head == null)
        {
            head = newNode;
            head.next = head;
        }
        else
        {
            Node temp = head;
            while(temp.next != head)
            {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = head;
        }
    }

    void display(Node head)
    {
        Node temp = head;
        do{
            System.out.println(temp.data);
            temp = temp.next;
        }while(temp != head);
    }

    void findAndSplit() {
        if(head == null || head.next == head)
        {
            return;
        }

        Node slow = head;
        Node fast = head;

        while(fast.next != head && fast.next.next != head)
        {
            slow = slow.next;
            fast = fast.next.next;
        }

        if(fast.next.next == head)
        {
            fast = fast.next;
        }

        Node head1 = head;
        Node head2 = slow.next;

        fast.next = slow.next;
        slow.next = head;

        System.out.println("First Circular Linked List:");
        display(head1);

        System.out.println("Second Circular Linked List:");
        display(head2);
    }

}
public class Problem2 {
    public static void main(String[] args) {
      CircularLinkedList var1 = new CircularLinkedList();
      var1.add(10);
      var1.add(20);
      var1.add(30);
      var1.add(40);

      var1.display(var1.head);
      var1.findAndSplit();

      var1.add(50);
      var1.add(60);
      var1.add(70);

            var1.display(var1.head);
      var1.findAndSplit();



    }


}
