#include <iostream>

using namespace std;

/**
Time Complexity: O(n) 
Auxiliary Space: O(n) for Recursion Call Stack.
*/
/** This function is not tail recursive 
	- but Tail recursive functions are always better than non-tail recursive 
		as it has some action to be done with the existing function.
*/
bool isSorted1(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;

    if (arr[n - 2] <= arr[n - 1])
        return isSorted1(arr, n - 1);

    return false;
}

/**
Time Complexity: O(n) 
Auxiliary Space: O(n) for Recursion Call Stack.
*/
// Tail recursive function
bool isSorted2(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;

    if (arr[n - 1] < arr[n - 2])
        return false;

    return isSorted2(arr, n - 1);
}

/**
Time Complexity: O(n) 
Auxiliary Space: O(1) 
*/
bool isSorted3(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;

    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
            return false;
}

int main()
{
    int arr[] = {12, 13, 15, 27, 19, 109};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSorted3(arr, n))
        cout << "Sorted";
    else
        cout << "Not sorted";
    return 0;
}
