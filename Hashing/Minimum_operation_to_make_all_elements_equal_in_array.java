import java.util.HashMap;
import java.util.Set;

/**
 * link:
 * https://www.geeksforgeeks.org/minimum-operation-make-elements-equal-array/
 * Example: Input : arr[] = {1, 2, 3, 4} Output : 3 Since all elements are
 * different, we need to perform at least three operations to make them same.
 * For example, we can make them all 1 by doing three subtractions. Or make them
 * all 3 by doing three additions.
 * 
 * Input : arr[] = {1, 1, 1, 1} Output : 0
 */
public class Minimum_operation_to_make_all_elements_equal_in_array {

    /*
     * Method to calculate the mininum number of operation to make the array of
     * equal values
     */
    public static int minOperation(int arr[], int n) {

        HashMap<Integer, Integer> hash = new HashMap<>();

        // Create a HashMap with items as key and their occurance count as value
        for (int i = 0; i < arr.length; i++)
            if (hash.containsKey(arr[i]))
                hash.put(arr[i], hash.get(arr[i]) + 1);
            else
                hash.put(arr[i], 1);

        int max_count = 0;
        Set<Integer> set = hash.keySet();

        for (int key : set) {
            if (max_count < hash.get(key))
                max_count = hash.get(key);
        }

        return n - max_count;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 5, 2, 1, 3, 2, 1 };
        int n = arr.length;
        System.out.print(minOperation(arr, n));
    }
}
