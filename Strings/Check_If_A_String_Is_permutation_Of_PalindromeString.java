public class Check_If_A_String_Is_permutation_Of_PalindromeString {

    /*
     * This is a bit-vector method
     */

    boolean isPermutationOfPalindrom(String str) {
        int bitVector = createBitVector(str);
        System.out.println("bitVector: " + Integer.toBinaryString(bitVector));
        return bitVector == 0 || checkExactlyOneBitSet(bitVector);
    }

    private int createBitVector(String str) {
        int bitVector = 0;
        System.out.println("createBitVector():");
        System.out.println("bitVector before: " + Integer.toBinaryString(bitVector));
        for (char c : str.toCharArray()) {
            int x = getCharNumber(c);
            bitVector = toggle(bitVector, x);
            System.out.println("bitVector after tog " + x + " is " + Integer.toBinaryString(bitVector));
        }
        System.out.println("bitVector final: " + Integer.toBinaryString(bitVector));
        System.out.println("createBitVector(): end\n");
        return bitVector;
    }

    private int toggle(int bitVector, int index) {
        System.out.println("toggle():");
        if (index < 0)
            return bitVector;

        int mask = 1 << index;
        System.out.println("mask: " + Integer.toBinaryString(mask));
        System.out.println("(bitVector & mask): " + Integer.toBinaryString((bitVector & mask)));
        if ((bitVector & mask) == 0) {
            bitVector |= mask;
            System.out.println("bitVector |= mask : " + Integer.toBinaryString(bitVector));
        } else {
            bitVector &= ~mask;
            System.out.println("bitVector &= ~mask: " + Integer.toBinaryString(bitVector));
        }
        System.out.println("toggle(): end\n");
        return bitVector;
    }

    private boolean checkExactlyOneBitSet(int bitVector) {
        System.out.println("checkExactlyOneBitSet():");
        System.out.println("(bitVector - 1): " + Integer.toBinaryString(((bitVector - 1))));
        System.out.println("bitVector & (bitVector - 1): " + Integer.toBinaryString((bitVector & (bitVector - 1))));
        System.out.println("checkExactlyOneBitSet( ) end :\n");
        return (bitVector & (bitVector - 1)) == 0;
    }

    private int getCharNumber(Character c) {
        System.out.println("getCharNumber():");
        int a = Character.getNumericValue('a');
        int z = Character.getNumericValue('z');
        int value = Character.getNumericValue(c);
        if (a <= value && value <= z) {
            System.out.println("value for " + c + " is " + value + " and (value - a) is " + (value - a));
            System.out.println("getCharNumber( ) end :\n");
            return value - a;
        }

        return -1;
    }

    public static void main(String[] args) {
        Check_If_A_String_Is_permutation_Of_PalindromeString obj = new Check_If_A_String_Is_permutation_Of_PalindromeString();
        boolean isPermutationOfPalindrom = obj.isPermutationOfPalindrom("mam");
        System.out.println(isPermutationOfPalindrom);

    }
}
