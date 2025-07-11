import java.util.Stack;

public class Problem5 {

    public static void reverseStack(Stack<Integer> stk)
    {
        Stack<Integer> temp = new Stack<>();

        while(!stk.isEmpty())
        {
            temp.push(stk.pop());
        }

                // Put back into original stack
        while (!temp.isEmpty()) {
            stk.push(temp.pop());
        }

    }

public static void displayStack(Stack<Integer> stk) {
    System.out.println("Top →");
    for (int i = stk.size() - 1; i >= 0; i--) {
        System.out.println("  " + stk.get(i));
    }
}

    public static void main(String[] args) {
        Stack<Integer> stk = new Stack<>();

        stk.push(10);
        stk.push(20);
        stk.push(30);
        stk.push(40);

        System.out.println("Original Stack:");
        displayStack(stk);

        reverseStack(stk);

        System.out.println("Reversed Stack:");
        displayStack(stk);
    }
}
