import java.util.HashMap;

class Count_distinct_elements_within_a_window {

    static void countDistinct(int arr[], int k) {
        // Create a hash map
        HashMap<Integer, Integer> hMap = new HashMap<>();

        // Traverse the first window and store the count of every element
        for (int i = 0; i < k; i++)
            hMap.put(arr[i], hMap.getOrDefault(arr[i], 0) + 1);

        // Print the count of the first window
        System.out.println(hMap.size());

        // Iterate over the next set of window
        for (int i = k; i < arr.length; i++) {

            // Remove the first element of the previous window, If there was only one window

            if (hMap.get(arr[i - k]) == 1) {
                hMap.remove(arr[i - k]);
            } else {
                // else reduce the count of the removed element
                hMap.put(arr[i - k], hMap.get(arr[i - k]) + 1);
            }

            /*
             * Add new element of the current window, if this element apprears for the first
             * time and set its count to 1
             */
            hMap.put(arr[i], hMap.getOrDefault(arr[i], 0) + 1);

            // Print the count of the current window
            System.out.println(hMap.size());
        }
    }

    public static void main(String args[]) {
        int arr[] = { 1, 2, 1, 3, 4, 2, 3, 3 };
        int k = 4;
        countDistinct(arr, k);
    }
}