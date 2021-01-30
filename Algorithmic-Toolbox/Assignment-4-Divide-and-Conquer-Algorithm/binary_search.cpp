#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*
Input Format: The first line of the input contains an integer n and a sequence a(0) < a(1) < ... < a(n-1) of n pairwaise distinct postive integers in increasing order. The next line contains an integer k and k positive integers b(0), b(1), ..., b(k-1).

Constraints: 1 <= n, k <= 10^4; 1 <= a(i) <= 10^9 for all 0 <= i <n; 1 <= b(j) <= 10^9 for all 0 <= j <k; 

Output Format: For alll i from 0 to k -1, output an index 0 <= j <= n-1 such that a(j) = b(i) or -1 if there is no such index.
*/
int binarySearch(long *arr, long searchItem)
{
    int position = -1;
    int size = sizeof(arr);
    int start = 0, end = size - 1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (searchItem == arr[mid])
        {
            position = mid;
            break;
        }
        else if (searchItem < arr[mid])
        {
            end = mid - 1;
        }
        else if (searchItem > arr[mid])
        {
            start = mid + 1;
        }
    }
    return position;
}

int main()
{

    int n, m;

    cin >> n;

    long arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> m;

    long searchItems[m];

    for (int i = 0; i < m; i++)
        cin >> searchItems[i];

    for (int i = 0; i < m; i++)
    {
        cout << binarySearch(arr, searchItems[i]) << " ";
    }

    return 0;
}
