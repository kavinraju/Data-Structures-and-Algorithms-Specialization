import java.util.ArrayList;
import java.util.HashMap;

/**
 * Link:
 * https://practice.geeksforgeeks.org/problems/match-specific-pattern/1/?category[]=Hash&category[]=Hash&page=1&query=category[]Hashpage1category[]Hash#
 * This is a practice problem in GeeksForGeeks and it has been added here just
 * for my learning reference.
 */
public class Match_pattern_from_the_list_of_words {

    // Returns the list of words that matches the @param pattern
    public static ArrayList<String> findMatchedWords(ArrayList<String> dict, String pattern) {

        // ArrayList to store the matchedWords
        ArrayList<String> matchedWords = new ArrayList<>();

        // Get the hash of pattern
        String hash = hashOfString(pattern);
        // Store the length of patterns
        int lenOfPattern = pattern.length();

        // Iterate the dict to check if anyone of the word's hash in the dict matches
        // the hash of pattern.
        for (String word : dict) {
            // Compare the length of the word and length of pattern and then check for the
            // hashes.
            if (word.length() == lenOfPattern && hashOfString(word).equals(hash)) {
                matchedWords.add(word);
            }
        }
        return matchedWords;
    }

    // Helper function to convert the string into hash string which consists of
    // numerical values.
    // Example:
    // -> A string "abbc" will be converted to "1223"
    // -> A string "hhc" will be converted to "112"
    // -> A string "xfgs" will be converted to "1234"
    public static String hashOfString(String str) {

        // This stores the string hash
        StringBuilder builder = new StringBuilder();

        // HashMap to store the unique character's and it's mapping to the numerical
        // value
        HashMap<Character, Integer> map = new HashMap<>();

        // numerical value that gets mapped to each new char in the str.
        int num = 0;
        char ch;

        for (int i = 0; i < str.length(); i++) {
            ch = str.charAt(i);

            // Map the ch and increment the num only if the ch is not in the mao
            if (!map.containsKey(ch))
                map.put(ch, num++);

            builder.append(map.get(ch));
        }

        return builder.toString();
    }

    public static void main(String[] args) {

        ArrayList<String> dict = new ArrayList<>();
        dict.add("abb");
        dict.add("bac");
        dict.add("mac");
        dict.add("kia");
        dict.add("yxy");

        String pattern = "foo";

        ArrayList<String> matchedWords = findMatchedWords(dict, pattern);

        if (matchedWords.size() == 0) {
            System.out.println("No matching words found with a pattern - " + pattern);
        } else {
            for (String word : matchedWords) {
                System.out.println(word);
            }
        }
    }
}