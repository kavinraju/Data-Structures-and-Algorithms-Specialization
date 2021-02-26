#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

int kadane(int arr[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here += arr[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_ending_here > max_so_far)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

/**
 * Note that the below algorithm doesn’t work if all numbers are negative e.g., {-1, -2, -3}. 
 * It returns 0 in this case. This case can be handled by adding a pre-check to see if all the 
 * numbers are negative before running the above
 * 
 * Time Complexity: O(n), where n is the number of elements in input array. As only linear traversal of the array is needed.
 * Auxiliary Space: O(1). As no extra space is required.
 */
int maxCircularSum(int arr[], int n)
{
    // Case 1: get the maximum sum using standard kadane's algorithm
    int max_kadane = kadane(arr, n);
    cout << "max_kadane = " << max_kadane << endl;

    // Case 2: Now find the maximum sum that includes corner elements.
    int max_wrap = 0;
    for (int i = 0; i < n; i++)
    {
        max_wrap += arr[i];
        arr[i] = -arr[i];
    }

    cout << "max_wrap = " << max_wrap << endl;
    cout << "kadane(a, n) = " << kadane(arr, n) << endl;

    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(arr, n);
    cout << "max_wrap = " << max_wrap << endl;

    return (max_wrap > max_kadane) ? max_wrap : max_kadane;
}

int main()
{
    int a[] = {1, -2, 3, -4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum circular sum : " << maxCircularSum(a, n) << endl;
    return 0;
}
