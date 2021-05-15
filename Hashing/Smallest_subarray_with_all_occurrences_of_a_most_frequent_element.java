import java.util.HashMap;

/*
 * Link: https://www.geeksforgeeks.org/smallest-subarray-with-all-occurrences-of-a-most-frequent-element/
 
    Input :  arr[] = {4, 1, 1, 2, 2, 1, 3, 3} 
    Output :   1, 1, 2, 2, 1
    The most frequent element is 1. The smallest
    subarray that has all occurrences of it is
    1 1 2 2 1

    Input :  A[] = {1, 2, 2, 3, 1}
    Output : 2, 2
    Note that there are two elements that appear
    two times, 1 and 2. The smallest window for
    1 is whole array and smallest window for 2 is
    {2, 2}. Since window for 2 is smaller, this is
    our output.
 */
public class Smallest_subarray_with_all_occurrences_of_a_most_frequent_element {

    private static void smallestSubsegment(int arr[], int n) {

        // To store left most occurrence of elements
        HashMap<Integer, Integer> left = new HashMap<>();

        // To store the count of each elements
        HashMap<Integer, Integer> count = new HashMap<>();

        // To store the maximum count value
        int max_freq = 0;

        // To store the value of length and starting index of the smallest result window
        int min_length = -1, start_index = -1;

        for (int i = 0; i < arr.length; i++) {
            int x = arr[i];

            // Find the first Occurrence of the element and store the count and index
            if (count.get(x) == null) {
                count.put(x, 1);
                left.put(x, i);
            } else {
                // increase the frequency of elements
                count.put(x, count.get(x) + 1);
            }

            // Find maximum repeated element and
            // store its last occurrence and first
            // occurrence
            if (count.get(x) > max_freq) {
                max_freq = count.get(x);

                // Update the length and starting index
                min_length = i - left.get(x) + 1;
                start_index = left.get(x);
            }
            // select subsegment of smallest size
            else if ((count.get(x) == max_freq) && (i - left.get(x) + 1 < min_length)) {

                // Update the length and starting index
                min_length = i - left.get(x) + 1;
                start_index = left.get(x);
            }
        }

        // Print the subsegment with all occurrences of
        // a most frequent element
        for (int i = start_index; i < min_length; i++)
            System.out.print(arr[i] + " ");
    }

    public static void main(String[] args) {
        int A[] = { 1, 2, 2, 2, 1 };
        int n = A.length;
        smallestSubsegment(A, n);
    }
}
