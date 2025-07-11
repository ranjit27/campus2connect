import java.util.*;

public class Problem4 {

    public static boolean isPalindrome(char[] arr)
    {
        int left = 0;
        int right = arr.length - 1;

        while (left < right) {
            if (arr[left] != arr[right]) {
                return false; // Not a palindrome
            }
            left++;
            right--;
        }
        return true; // Is a palindrome
    }
    public static void main(String[] args) {
        char[] input = {'a', 'b', 'a', 'b', 'X', 'b', 'a', 'b', 'a'};
        
        if (isPalindrome(input)) {
            System.out.println("The array represents a palindrome.");
        } else {
            System.out.println("The array is not a palindrome.");
        }
    }
}
