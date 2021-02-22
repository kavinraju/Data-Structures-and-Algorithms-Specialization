#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/

int binarySearch(int arr[], int n, int f)
{
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {

        if (arr[mid] == f)
            return mid;
        else if (arr[mid] > f)
            end = mid - 1;
        else if (arr[mid] < f)
            start = mid + 1;

        mid = (start + end) / 2;
    }
    return -1;
}

/**
Time Complexity : O(Log n + count) 
*/
int count(int arr[], int n, int f)
{
    // Find the index of the element f
    int index = binarySearch(arr, n, f);

    if (index == -1)
        return -1;

    int left = index - 1, right = index + 1, count = 1;

    // Loop for the left occurences from index - 1
    while (left >= 0 && arr[left] == f)
        left--, count++;

    // Loop for the right occurences from index + 1
    while (right <= n - 1 && arr[right] == f)
        right++, count++;

    return count;
}

/**
Time Complexity : O(Log n) 
*/
int count2(int arr[], int n, int f)
{
    int *low = lower_bound(arr, arr + n, f);

    if (low == (arr + n) || *low != f)
        return 0;

    int *high = upper_bound(arr, arr + n, f);

    return high - low;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int find = 3;
    int c = count2(arr, n, find);
    if (c > 0)
        cout << "Count: " << c;
    else
        cout << "Element not found ";
    return 0;
}
