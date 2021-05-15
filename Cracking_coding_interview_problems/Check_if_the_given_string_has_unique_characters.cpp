#include <iostream>
//#include <bits/stdc++.h>

using namespace std;
/**
 * This checks only for the charcters a to z.
 * Time complexity: O(N)
 * Space complexity: O(N)/8 [i.e eight times less than the O(N) space complexity]
*/
bool checkIfStringHasUniqueCharacters(string str)
{
    // declare a variable to store the checked char's bit value
    int checker = 0;
    for (int i = 0; i < str.length(); i++)
    {
        // store the char value as 0 to 25
        int val = str.at(i) - 'a';
        cout << "val = " << val << endl;

        cout << "(checker & (1 << val) = " << (checker & (1 << val)) << endl;
        // check if the bit at position val is set in the checker variable
        if ((checker & (1 << val)) > 0)
            return false;

        // Set the bit at position val in the checker variable
        checker |= (1 << val);
        cout << "checker |= (1 << val) = " << checker << "\n\n";
    }
    return true;
}

/**
 * This checks for the ASCII charcters.
 * Time complexity: O(N)
 * Space complexity: O(N)
*/
bool hasUniqueChars(string str)
{
    if (str.length() > 128)
        return false;

    bool char_set[128] = {false};
    for (int i = 0; i < str.length(); i++)
    {
        int val = str.at(i);
        cout << "val = " << val << endl;
        if (char_set[val])
            return false;

        char_set[val] = true;
    }
    return true;
}

int main()
{
    string s = "a90--z";
    bool hasUniqueCharacters = checkIfStringHasUniqueCharacters(s);

    if (hasUniqueCharacters)
        cout << "Is unique";
    else
        cout << "Not unique";

    cout << endl
         << "\nUnicode check: \n";
    hasUniqueCharacters = hasUniqueChars(s);

    if (hasUniqueCharacters)
        cout << "Is unique";
    else
        cout << "Not unique";
    return 0;
}
