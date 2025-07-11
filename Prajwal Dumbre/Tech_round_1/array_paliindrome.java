public class array_paliindrome {

    static boolean calculate(char[] arr){
        int i =0;
        int j = arr.length-1;

        while (arr[i]!='x' || arr[j]!='x' ) {
            if(arr[i] != arr[j]){
                return false;
            }
            i++;
            j--;
        }

        if(i==j){
            return true;
        }else{
            return false;
        }

    }
    public static void main(String[] args) {
        char [] arr = {'a','c','x','b','a'};
        System.err.println(calculate(arr));        
    }
}
