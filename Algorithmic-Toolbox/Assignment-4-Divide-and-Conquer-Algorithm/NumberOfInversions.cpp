#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int inversions = 0;

void merge(int *a, int start, int mid, int end)
{
    if (a[mid - 1] <= a[mid])
        return;

    int i = start, j = mid, tempIndex = 0;
    int temp[end - start];

    while (i < mid && j < end)
        if (a[i] <= a[j])
        {
            temp[tempIndex++] = a[i++];
        }
        else
        {
            inversions += (mid - i); // KEY ELEMENT FOR THIS PROGRAM
            //cout << "a[i], a[j] " << a[i] << "," << a[j] << endl;
            temp[tempIndex++] = a[j++];
        }

    // Copy the remaining elements into temp[] from the first half
    while (i < mid)
    {
        temp[tempIndex++] = a[i++];
    }

    // Copy the remaining elements into temp[] from the second half
    while (j < end)
    {
        temp[tempIndex++] = a[j++];
    }

    // Rest the tempIndex and i to its initial positions
    tempIndex = 0;
    i = start;

    // Copy back the sorted elements stored in temp[] into the original array a[]
    while (i < end)
    {
        a[i++] = temp[tempIndex++];
    }
}

void mergeSort(int *a, int start, int end)
{

    if (end - start < 2)
        return;

    int mid = (start + end) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid, end);
    merge(a, start, mid, end);
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n);

    cout << inversions;
}
