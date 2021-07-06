
class Subarray_count_with_elements_greater_than_K {

    /**
     * This function calculates the subarray count whose elements are greater
     * than @param K
     * 
     * @param arr
     * @param K
     * @return
     */
    static int subarrayCountWithElementsGreaterThanNumberK(int arr[], int K) {
        int len = arr.length;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] > K) {
                int lenOfSubArray = 0;
                while (i < len && arr[i] > K) {
                    lenOfSubArray++;
                    count++;
                    i++;
                }
                if (lenOfSubArray > 1)
                    count++;
            }
        }

        return count;
    }

    static int maxLengthOfSubarraytWithElementsGreaterThanNumberK(int arr[], int K) {
        int len = arr.length;
        int maxLengthOfSubArray = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] > K) {
                int lenOfSubArray = 0;
                while (i < len && arr[i] > K) {
                    lenOfSubArray++;
                    i++;
                }
                maxLengthOfSubArray = Math.max(lenOfSubArray, maxLengthOfSubArray);
            }
        }

        return maxLengthOfSubArray;
    }

    public static void main(String[] args) {
        int arr[] = { 8, 25, 10, 19, 19, 18, 20, 11, 18 }, K = 13; // INPUT 1
        // int arr[] = { 3, 4, 5, 6, 7, 2, 10, 11 }, K = 5; // INPUT 2
        int subarrayCount = subarrayCountWithElementsGreaterThanNumberK(arr, K);
        System.out.println("Subarray count with elements greater than K = " + K + " is " + subarrayCount);

        int maxLengthOfSubArray = maxLengthOfSubarraytWithElementsGreaterThanNumberK(arr, K);
        System.out.println("Max Length of subArray with elements greater than K = " + K + " is " + maxLengthOfSubArray);

        // This for loop prints:
        // 1<<0: 1
        // 1<<1: 10
        // 1<<2: 100
        // 1<<3: 1000
        // 1<<4: 10000
        for (int i = 0; i < 5; i++) {
            System.out.println("1<<" + i + ": " + Integer.toBinaryString((1 << i)));
        }
    }
}