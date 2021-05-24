import java.util.*;
/*  
    Reverse a string without affecting the position of special chars
//  AB#1CD$E%F --> FE#DC1$B%A
*/

public class Reverse_A_String_Without_Affecting_Special_Characters {

    public static void main(String args[]) {
        String input = "AB#CD$E%F^RTS";
        char[] arr = input.toCharArray();

        for (int i = 0, j = input.length() - 1; i < input.length() / 2;) {

            char c1 = input.charAt(i), c2 = input.charAt(j);

            if (Character.isAlphabetic(c1) && Character.isAlphabetic(c2)) {
                char t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i++;
                j--;
            } else if ((Character.isAlphabetic(c1) && !Character.isAlphabetic(c2))) {
                j--;
            } else if ((!Character.isAlphabetic(c1) && Character.isAlphabetic(c2))) {
                i++;
            } else if (!Character.isAlphabetic(c1) && !Character.isAlphabetic(c2)) {
                i++;
                j--;
            }
        }

        System.out.println("Output: " + new String(arr));
    }
}