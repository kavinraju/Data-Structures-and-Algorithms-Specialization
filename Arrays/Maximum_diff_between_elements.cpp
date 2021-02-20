#include <iostream>

using namespace std;

//https://www.geeksforgeeks.org/maximum-difference-between-two-elements/

/**
Time Complexity: O(n) 
Auxiliary Space: O(1) 
*/
int maximumDifferenceBetweenElements(int arr[], int n)
{
    int max_diff = arr[1] - arr[0];
    int min_element = arr[0];

    for (int i = 1; i < n; i++)
    {
        // Track for maximum difference
        if (arr[i] - min_element > max_diff)
            max_diff = arr[i] - min_element;

        // Track for minimum element
        if (arr[i] < min_element)
            min_element = arr[i];
    }

    return max_diff;
}

int main()
{
    int arr[] = {1, 2, 90, 10, -90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximumDifferenceBetweenElements(arr, n);
    return 0;
}
