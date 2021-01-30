#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
Input Format: The first line of the input contains an integer n and a sequence a(0) < a(1) < ... < a(n-1) of n pairwaise distinct postive integers in increasing order. The next line contains an integer k and k positive integers b(0), b(1), ..., b(k-1).

Constraints: 1 <= n, k <= 10^4; 1 <= a(i) <= 10^9 for all 0 <= i <n; 1 <= b(j) <= 10^9 for all 0 <= j <k; 

Output Format: For alll i from 0 to k -1, output an index 0 <= j <= n-1 such that a(j) = b(i) or -1 if there is no such index.
*/

int binarySearch(long *arr, int size, long searchItem)
{
    int position = -1;
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

/*
Merge Sort Algorithm to sort the array generated in stress test
*/
void merge(long *a, int start, int mid, int end)
{

    if (a[mid - 1] <= a[mid])
        return;

    int i = start;
    int j = mid;
    int tempIndex = 0;
    long temp[end - start]; // Create a temp array to store the sorted elements.

    while (i < mid && j < end)
        temp[tempIndex++] = a[i] <= a[j] ? a[i++] : a[j++]; // Compare and store the elements into temp[]

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

void mergeSort(long *a, int start, int end)
{

    if (end - start < 2)
        return;

    int mid = (start + end) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid, end);
    merge(a, start, mid, end);
}

/*
    stressTest() function generates a randomn numbers to run the test on k number of test cases.
*/
void stressTest()
{
    srand(time(0));

    // Initialize n for number elements in the array, k for number testcases
    int n = rand() % 10000 + 1;
    int k = rand() % 10000 + 1;

    long arr[n], searchItems[k];

    // Generate the random numbers and store into arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000000 + 1;
    }

    cout << "n = " << n << ", k = " << k << endl;

    // Sort the arr
    mergeSort(arr, 0, n);

    // Print the arr
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        if (i % 10 == 0)
            cout << endl;
    }
    cout << endl;
    cout << endl;

    // Select the random elements from arr and store it in searchItems, of k elements, to run the test cases.
    for (int i = 0; i < k; i++)
    {
        int j = (rand() % (n + 1));
        if (i % 3 == 0 || i % 6 == 0)
            searchItems[i] = arr[j];
        else
            searchItems[i] = rand() % 1000000 + 1;
    }
    cout << endl;

    // Print the Search items
    cout << "Search Items:" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << searchItems[i] << " ";
        if (i % 10 == 0)
            cout << endl;
    }

    // binary search the elements in searchItems and check if it's correct or not.
    for (int i = 0; i < k; i++)
    {
        int position = binarySearch(arr, n, searchItems[i]);
        if (position == -1)
            cout << " Not Found " << searchItems[i] << endl;
        else if (arr[position] == searchItems[i])
            cout << "Found " << searchItems[i] << " at " << position << endl;
    }
}

int main()
{

    // Uncomment the below line to run the stressTest()
    //stressTest();

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
        cout << binarySearch(arr, n, searchItems[i]) << " ";
    }

    return 0;
}
