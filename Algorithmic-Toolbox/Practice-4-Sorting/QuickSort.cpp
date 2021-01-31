#include <iostream>
using namespace std;

/*
    Helper function to swap the values stored at the given pointer variables.
*/
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*
	partition() is a function to sort the array arr[] within the range from low to high
    arr[] is the array
    low is the left index
    high is the right index
    This function does the actual sorting by selecting the element the position 'high' as
    the pivot element.
*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/*
	quickSort() is a function to sort the array arr[].
    arr[] is the array
    low is the left index
    high is the right index
*/
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    // Get the input
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Call the quickSort function to do the sorting
    quickSort(arr, 0, n - 1);

    // Print the sorted array.
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
