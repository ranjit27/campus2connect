//polindrome.java
public class polindrome
{
    Node head;
    class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }

    public void add(int data)
    {
      Node newNode=new Node(data);
      if(head==null)
      {
        head=newNode;
      }
      newNode.next=head;
      head=newNode;

    }
     public void print()
     {
        Node curr=head;
        while(curr!=null)
        {
            System.out.print(curr.data+"->");
            curr=curr.next;
        }
     }
    public boolean checkPolindrome()
    {
        Node slow=head;
        Node fast=head;
        Node prev=null;

        
        while(fast!=null && fast.next!=null)
        {
            prev=slow;
            slow=slow.next;
            fast=fast.next.next;
        }

        
        if(fast!=null)
        {
            slow=slow.next;
        }

        
        Node prevHalf=null;
        while(slow!=null)
        {
            Node nextNode=slow.next;
            slow.next=prevHalf;
            prevHalf=slow;
            slow=nextNode;
        }

   
        Node firstHalf=head;
        Node secondHalf=prevHalf;

        while(secondHalf!=null)
        {
            if(firstHalf.data!=secondHalf.data)
            {
                return false; 
            }
            firstHalf=firstHalf.next;
            secondHalf=secondHalf.next;
        }
        
        return true; 
  
    }
}