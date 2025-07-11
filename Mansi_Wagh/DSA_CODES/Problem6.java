//Given an integer k and a queue of integers, how do you reverse the order of the first k elements of the queue, 
//leaving the other elements in the same relative order? For example, if k=4 and queue has the elements [10, 20, 30, 40, 50, 60, 70, 80, 90]; the output should be [40, 30, 20, 10, 50, 60, 70, 80, 90]

import java.util.*;
import java.util.LinkedList;

public class Problem6 {

    public static void reverseFirstKElements(Queue<Integer> queue, int k)
    {
        Stack<Integer> stk = new Stack<>();

        for(int i = 0; i < k && !queue.isEmpty(); i++)
        {
            stk.push(queue.poll());
        }

        while(!stk.isEmpty())
        {
            queue.add(stk.pop());
        }

        int remainingElem = queue.size() - k;

        for(int i = 0; i < remainingElem; i++)
        {
            queue.add(queue.poll());
        }
    }
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(10);
        queue.add(20);
        queue.add(30);
        queue.add(40);
        queue.add(50);
        queue.add(60);
        queue.add(70);
        queue.add(80);
        queue.add(90);
        
        int k = 4;

        System.out.println("Original Queue: " + queue);
        reverseFirstKElements(queue, k);
        System.out.println("Modified Queue: " + queue); 
    }
}
