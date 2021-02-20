#include <iostream>
#include <vector>
using namespace std;

// Function to reverse an array
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void leftArrayRotation(int arr[], int d)
{
    int n = sizeof(arr) - 1; /// sizeof(arr)  return size of arr + 1
    //cout << "n = " << n << endl;
    if (d == 0)
        return;

    // calculaion of reverse number in case d > n
    d = d % n;
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    leftArrayRotation(arr, d);

    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ",";
    return 0;
}
