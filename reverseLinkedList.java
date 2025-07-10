import java.util.Scanner;

class Node{
    int data;
    Node next;

    Node(int data){
        this.data=data;
        this.next=null;
    }
}

public class reverseLinkedList{
    public static void printReverse(Node head){
        if(head==null)
        return;
        printReverse(head.next);
        System.out.print(head.data+" ");
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Node head=null, tail=null;
        System.out.println("Enter number of elements");
        int n=sc.nextInt();
        System.out.println("Enter the elements");
        for(int i=0;i<n;i++){
            int data=sc.nextInt();
            Node newNode= new Node(data);
            if(head==null){
                head=newNode;
                tail=newNode;
            }
            else{
                tail.next=newNode;
                tail=newNode;
            }
        }
        System.out.println("Linked list in reverse: ");
        printReverse(head);
    }
}