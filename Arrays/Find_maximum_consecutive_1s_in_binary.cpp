#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//https://www.geeksforgeeks.org/maximum-consecutive-ones-or-zeros-in-a-binary-array/

/**
Time Complexity: O(n) 
Auxiliary Space: O(1) 
*/
int findMaximumConsecutive1s(int arr[], int n)
{
    // Initialize max count
    int max_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int count = -1;
        // If arr[i] is 1 then iterate through and find how many 1s are there consecutively
        if (arr[i] == 1)
        {
            count = 1;
            while (arr[i + 1] == 1)
            {
                i++;
                count++;
            }
        }

        // If count is greater than max_count assign it max_count
        if (count > max_count)
            max_count = count;
    }

    return max_count;
}

int main()
{
    int arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_1s = findMaximumConsecutive1s(arr, n);
    cout << "Maximum 1s: " << max_1s;
    return 0;
}
