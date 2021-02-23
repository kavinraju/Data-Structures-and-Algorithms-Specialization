#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/**
 * Recursively print the Sub Arrays of an array
 * */
void printSubsequencesRecursively(vector<int> arr, int start, int end)
{
    // Return if the reached end of the array
    if (end == arr.size())
        return;

    // Start printing from 0 to end+1 if start > end
    else if (start > end)
        printSubsequencesRecursively(arr, 0, end + 1);
    else
    {

        // Print from start to end
        cout << "[";
        for (int i = start; i < end; i++)
            cout << arr[i] << ", ";

        cout << arr[end] << "]" << endl;

        // Call the function to recursively print from start+1 to end
        //(this function call only makes the start > end)
        printSubsequencesRecursively(arr, start + 1, end);
    }
    return;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    printSubsequencesRecursively(arr, 0, 0);
    return 0;
}
