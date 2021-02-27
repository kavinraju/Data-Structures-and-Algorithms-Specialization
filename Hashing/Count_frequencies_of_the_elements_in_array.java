import java.util.HashMap;

public class Count_frequencies_of_the_elements_in_array {

    public static void main(String[] args) {
        int arr[] = { 1, 2, 1, 3, 4, 2, 3, 3 };
        HashMap<Integer, Integer> hMap = countFrequenciesOfElements(arr);
        Integer x = findCount(hMap, arr[3]);
        if (x == -1)
            System.out.println("Element not in array. ");
        else
            System.out.println("Count of " + x + " is " + x);
    }

    private static Integer findCount(HashMap<Integer, Integer> hMap, int x) {
        return hMap.getOrDefault(x, -1);
    }

    private static HashMap<Integer, Integer> countFrequenciesOfElements(int[] arr) {

        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            hashMap.put(arr[i], hashMap.getOrDefault(arr[i], 0) + 1);
        }
        System.out.println(hashMap);
        return hashMap;
    }
}
