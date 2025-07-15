public class CheckMiddleXPalindrome {

    public static boolean isPalindrome(char[] arr) {
        int n = arr.length;
        int mid = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'X') {
                mid = i;
                break;
            }
        }

        if (mid == -1) {
            System.out.println("Middle marker 'X' not found.");
            return false;
        }

        int left = mid - 1;
        int right = mid + 1;

        while (left >= 0 && right < n) {
            if (arr[left] != arr[right]) {
                return false;
            }
            left--;
            right++;
        }

        return true;
    }

    public static void main(String[] args) {
        char[] input1 = {'a', 'b', 'a', 'X', 'a', 'b', 'a'}; 
        char[] input2 = {'a', 'b', 'a', 'X', 'b', 'a', 'a'}; 

        System.out.println("Is input1 palindrome: " + isPalindrome(input1));
        System.out.println("Is input2 palindrome: " + isPalindrome(input2));
    }
}
