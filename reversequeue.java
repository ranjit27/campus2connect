import java.util.Scanner;

public class reversequeue {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of elements in queue: ");
        int n = scanner.nextInt();

        int[] queue = new int[n];
        System.out.println("Enter the elements of the queue:");
        for (int i = 0; i < n; i++) {
            queue[i] = scanner.nextInt();
        }

        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();

        if (k > n || k < 0) {
            System.out.println("Invalid value of k. It must be between 0 and " + n);
            return;
        }

        reverseFirstKElements(queue, k);

        System.out.println("Queue after reversing first " + k + " elements:");
        for (int elem : queue) {
            System.out.print(elem + " ");
        }

        scanner.close();
    }

    public static void reverseFirstKElements(int[] queue, int k) {
        int start = 0;
        int end = k - 1;

        while (start < end) {
            int temp = queue[start];
            queue[start] = queue[end];
            queue[end] = temp;
            start++;
            end--;
        }
    }
}