#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

int maxSubArraySum1(int arr[], int n)
{
    int max_so_far = arr[0];
    int curr_sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr_sum = max(arr[i], curr_sum + arr[i]);
        max_so_far = max(max_so_far, curr_sum);
    }
    return max_so_far;
}

// To print the subarray with the maximum sum, we maintain indices whenever we get the maximum sum.
void maxSubArraySum2(int arr[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0, start = 0, end = 0, s = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here += arr[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    cout << "Max sum = " << max_so_far
         << " from index " << start << " to " << end << endl;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}; //{2, 3, -4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArraySum1(arr, n);
    cout << "Max sum = " << max_sum << endl;

    maxSubArraySum2(arr, n);
    return 0;
}