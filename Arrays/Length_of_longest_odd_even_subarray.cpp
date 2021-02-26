#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/length-of-the-longest-alternating-even-odd-subarray/

int lengthOfLongestOddEvenSubarray(int arr[], int n)
{
    int counter = 1, max_length = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if ((arr[i] + arr[i + 1]) % 2 != 0)
        {
            counter++;
            max_length = counter;
        }
        else
            counter = 1;
    }
    return max_length;
}

int lengthOfLongestOddEvenSubarray2(int arr[], int n)
{
    int counter = 1, max_length = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if ((arr[i] + arr[i + 1]) % 2 != 0)
            counter++;
        else
        {
            max_length = max(counter, max_length);
            counter = 1;
        }
    }

    return max(counter, max_length);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int longest_length = lengthOfLongestOddEvenSubarray(arr, n);
    cout << "Length Of Longest Odd Even Subarray = " << longest_length << endl;

    return 0;
}
