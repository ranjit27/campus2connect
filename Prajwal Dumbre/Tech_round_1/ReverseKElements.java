import java.util.*;

public class ReverseKElements {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(Arrays.asList(10, 20, 30, 40, 50, 60, 70, 80, 90));
        int k = 4;

        Queue<Integer> result = reverseFirstK(queue, k);
        System.out.println(result);
    }

    public static Queue<Integer> reverseFirstK(Queue<Integer> queue, int k) {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < k; i++) {
            stack.push(queue.poll());
        }
        while (!stack.isEmpty()) {
            queue.add(stack.pop());
        }
        int size = queue.size();
        for (int i = 0; i < size - k; i++) {
            queue.add(queue.poll());
        }
        return queue;
    }
}
