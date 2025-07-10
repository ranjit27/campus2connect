import java.util.Scanner;



public class arraypalindrome {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        


        System.out.print("Enter the string containing 'a', 'b' and exactly one 'X' in the middle: ");

        String input = scanner.nextLine();

        


        int middleIndex = input.indexOf('X');

        

        if (middleIndex == -1) {

            System.out.println("Invalid input! String must contain 'X' as the middle marker.");

            return;

        }

        


        String firstHalf = input.substring(0, middleIndex);

        String secondHalf = input.substring(middleIndex + 1);

        


        String reversedSecondHalf = new StringBuilder(secondHalf).reverse().toString();

        


        if (firstHalf.equals(reversedSecondHalf)) {

            System.out.println("The string is a palindrome around 'X'.");

        } else {

            System.out.println("The string is NOT a palindrome around 'X'.");

        }

        

        scanner.close();

    }

}