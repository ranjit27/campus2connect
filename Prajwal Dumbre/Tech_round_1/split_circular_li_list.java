class Node{
    int val;
    Node next;

    public Node(int val){
        this.val = val;
        this.next = null;
    }
}

public class split_circular_li_list {
    static int  countNodes(Node head){
        int nodes = 0;
        Node h = head;

        while(h.next != head){
            nodes+= 1;
            h = h.next;
        }

        return nodes;
    }

    static Node[] split(Node head, int mid){
        Node n = head;
        int count = 1;
        while(count != mid){
            n = n.next;
            count +=1;
        }

        Node h2 = n.next;
        n.next = head;

        Node s = h2;
        while(s.next != head){
            s = s.next;
        }

        s.next = h2;

        Node[]ans = {head, h2};
        return ans ;
    }

    static void printList(Node head){
        Node h = head;
        do {
            System.out.print(h.val + "->");
            h = h.next;
        } while (h != head);
    }

    public static void main(String[] args) {
        Node head = new Node(0);
        Node k = head;
        for(int i =1; i<9;i++){
            Node t = new Node(i);
            k.next = t;
            k = k.next;
        }

        k.next = head;
        System.out.println("List _main");
        printList(head);


        int mid= countNodes(head)/2;

        Node[]splited = split(head,mid+1);

      
        System.out.println("");

        System.out.println( "List 1");
        printList(splited[0]);
        System.out.println("");
        System.out.println("List 2");
        printList(splited[1]);


        
    }
}
